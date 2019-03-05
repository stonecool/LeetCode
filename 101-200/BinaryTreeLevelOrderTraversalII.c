/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize) {
    if (NULL == root)
        return NULL;
    
    int totalRet = 16, cur = 0, bakcur = 0, depth = 0, total = 16;
    
    struct TreeNode **q1 = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * total);
    struct TreeNode **q2 = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * total);
    struct TreeNode ***curq = &q1, ***bakq = &q2, ***temp = NULL;
    
    memset(q1, 0, sizeof(struct TreeNode*) * total);
    memset(q2, 0, sizeof(struct TreeNode*) * total);
    
    int** ret = (int **)malloc(sizeof(int *) * totalRet);
    memset(ret, 0, sizeof(int *) * total);
    
    *columnSizes = (int *)malloc(sizeof(int) * totalRet);
    memset(*columnSizes, 0, sizeof(int) * total);
    
    (*curq)[cur++] = root;
    
    while (cur > 0)
    {   
        (*columnSizes)[depth] = cur;
        ret[depth] = (int *)malloc(sizeof(int) * cur);
        
        for (int i = 0; i < cur; ++i)
        {
            ret[depth][i] = (*curq)[i]->val;
            
            if ((*curq)[i]->left)
            {
                (*bakq)[bakcur++] = (*curq)[i]->left;
                if (bakcur == total)
                {
                    total <<= 1;
                    (*curq) = (struct TreeNode**)realloc(*curq, sizeof(struct TreeNode*) * total);
                    memset(*curq + bakcur, 0, sizeof(struct TreeNode*) * bakcur);
                    (*bakq) = (struct TreeNode**)realloc(*bakq, sizeof(struct TreeNode*) * total);
                    memset(*bakq + bakcur, 0, sizeof(struct TreeNode*) * bakcur);
                }
            }
            
            
            if ((*curq)[i]->right)
            {
                (*bakq)[bakcur++] = (*curq)[i]->right;
                
                if (bakcur == total)
                {
                    total <<= 1;
                    (*curq) = (struct TreeNode**)realloc(*curq, sizeof(struct TreeNode*) * total);
                    memset(*curq + bakcur, 0, sizeof(struct TreeNode*) * bakcur);
            
                    (*bakq) = (struct TreeNode**)realloc(*bakq, sizeof(struct TreeNode*) * total);
                    memset(*bakq + bakcur, 0, sizeof(struct TreeNode*) * bakcur);
                }
            }

        }

        temp = curq;
        curq = bakq;
        bakq = temp;
             
        cur = bakcur;
        bakcur = 0;

        ++depth;
        if (depth == totalRet)
        {
            totalRet <<= 1;
            ret = (int **)realloc(ret, sizeof(int *) * totalRet);
            memset(ret + depth, 0, sizeof(int *) * depth);
            
            (*columnSizes) = (int *)realloc(*columnSizes, sizeof(int) * totalRet);
            memset((*columnSizes) + depth, 0, sizeof(int) * depth);
        }
    }
 
    
    free(q1);
    free(q2);
    
    *returnSize = depth;
    
    for (int i = 0; i < depth / 2; ++i)
    {
        int *p = ret[i];
        ret[i] = ret[depth - 1 - i];
        ret[depth - 1 - i] = p;
        
        int t = (*columnSizes)[i];
        (*columnSizes)[i] = (*columnSizes)[depth - 1 - i];
        (*columnSizes)[depth - 1 - i] = t;
    }
    
    return ret;
}

// 入队
/*
void queuePush(struct TreeNode** tail, struct TreeNode* p)
{
    (*tail)->next = p;
    *tail = p;
    (*tail)->next = NULL;
}

// 出队
struct TreeNode* queuePop(struct TreeNode **head)
{
    struct TreeNode *p = *head;
    (*head) = (*head)->next;
    
    return p;
}
想用一个队列的方式处理，这样就会把传入的参数root树拆掉。不一样，还是得按第一种想法来
*/

// memset，例如90行
// memset((*columnSizes) + depth, 0, sizeof(int) * depth); // right
// memset((*columnSizes) + sizeof(int) * depth, 0, sizeof(int) * depth); // wrong
