/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void findLeftLeaves(struct TreeNode* root, int direct, int* sum){
    if(!root)
        return;
    
    if(root->left == NULL && root->right == NULL && direct){
        *sum += root->val;
        findLeftLeaves(root->right, 0, sum);
    } else{
        findLeftLeaves(root->left, 1, sum);
        findLeftLeaves(root->right, 0, sum);
    } 
}

int sumOfLeftLeaves(struct TreeNode* root){
    int sum=0;
    
    findLeftLeaves(root->left, 1, &sum);
    findLeftLeaves(root->right, 0, &sum);
    
    return sum;
}