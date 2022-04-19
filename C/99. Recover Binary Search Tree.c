/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* previous = NULL;
struct TreeNode* first = NULL;
struct TreeNode* second = NULL;

void solve(struct TreeNode* root){        
    if(!root)
        return;
    
    solve(root->left);

    if(previous && root->val < previous->val){
        if(!first)
            first = previous;
        second = root;
    }
    
    previous = root;

    solve(root->right);    
}

void recoverTree(struct TreeNode* root){
    solve(root);
        
    int temp = first->val;
    first->val = second->val;
    second->val = temp;
}