/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void CompeteTree(struct TreeNode* root, int* ans){
    if(root){
        *ans+=1;
        CompeteTree(root->left, ans);
        CompeteTree(root->right, ans);
    }
    
    return;
}

int countNodes(struct TreeNode* root){
    int ans = 0;
    
    CompeteTree(root, &ans);
    
    return ans;
}