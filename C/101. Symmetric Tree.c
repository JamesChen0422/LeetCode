
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool Symmetric(struct TreeNode* left, struct TreeNode* right){
    if(!left || !right)
        return left == right;
    if(left->val != right->val)
        return false;
    else
        return Symmetric(left->left, right->right) && Symmetric(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root){
    if(!root)
        return true;
    return Symmetric(root->left, root->right);
}