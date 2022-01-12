/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sum(struct TreeNode* root, int num){
    if(!root){       
        return 0;
    }
    
    num = (num << 1) | root->val;
    
    if(!root->right && !root->left)
        return num;
    
    return sum(root->left, num)+sum(root->right, num);
}

int sumRootToLeaf(struct TreeNode* root){
    return sum(root, 0);
}