/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int Match(struct TreeNode* root, int targetSum, int sum){
    if (root==NULL)
        return 0;
    if(sum+root->val==targetSum){
        return 1 + Match(root->left, targetSum, sum+root->val) + Match(root->right, targetSum, sum+root->val);
    } else 
        return Match(root->left, targetSum, sum+root->val) + Match(root->right, targetSum, sum+root->val);
}

int pathSum(struct TreeNode* root, int targetSum){
    if(!root)
        return 0;
    else
        return Match(root, targetSum, 0) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
}