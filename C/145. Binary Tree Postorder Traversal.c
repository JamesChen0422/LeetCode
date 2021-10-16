/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void postorder(struct TreeNode* root, int* result, int* returnSize){
    if(!root)
        return;
    
    postorder(root->left, result, returnSize);   
    postorder(root->right, result, returnSize);
    result[(*returnSize)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int* result = malloc(100 * sizeof(int));
    *returnSize = 0;
    
    postorder(root, result, returnSize);
    return result;
}