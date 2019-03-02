/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    if (NULL == root)
        return 0;
    
    int left = 0, right = 0;
    
    if (root->left)
        left = maxDepth(root->left);
    if (root->right)
        right = maxDepth(root->right);
    
    return left > right ? left + 1 : right + 1;
}
