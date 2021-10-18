/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool PathSum(struct TreeNode* root, int targetSum, int sum){
    if (root==NULL)
        return false;
    if(sum+root->val==targetSum){
        if(!(root->left) && !(root->right))
            return true;
    }
    
    return PathSum(root->left, targetSum, sum+root->val) | PathSum(root->right, targetSum, sum+root->val);
}

bool hasPathSum(struct TreeNode* root, int targetSum){
    if(!root)
        return 0;
    else
        return PathSum(root, targetSum, 0);
}