/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// 23:51 - 00:00
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (NULL == p && NULL == q)
        return true;
    
    if (NULL == p || NULL == q)
        return false;
    
    if (p->val != q->val)
        return false;
    
    if (! isSameTree(p->left, q->left))
        return false;
    
    if (! isSameTree(p->right, q->right))
        return false;
    
    return true;
}

