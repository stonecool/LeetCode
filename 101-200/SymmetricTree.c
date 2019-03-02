/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// 00:02 - 00:07
bool isMirrorTree(struct TreeNode* p, struct TreeNode* q) {
    if (NULL == p && NULL == q)
        return true;
    
    if (NULL == p || NULL == q)
        return false;
    
    if (p->val != q->val)
        return false;
    
    if (! isMirrorTree(p->left, q->right))
        return false;
    
    if (! isMirrorTree(p->right, q->left))
        return false;
    
    return true;
}

bool isSymmetric(struct TreeNode* root) {
    if (NULL == root)
        return true;
    
    return isMirrorTree(root->left, root->right);
}
