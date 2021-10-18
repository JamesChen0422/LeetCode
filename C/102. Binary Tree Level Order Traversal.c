/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int maxDepth(struct TreeNode* root){
    if(root){
        int left, right;
        left = maxDepth(root->left);
        right = maxDepth(root->right);
        return left>right ? left+1 : right+1;
    } else 
        return 0;
}

void Traversal(struct TreeNode* root, int layer, int** ans, int* returnColumnSizes){
    if(root==NULL)
        return;
    
    ans[layer][returnColumnSizes[layer]] = root->val;
    returnColumnSizes[layer]++;
    
    Traversal(root->left, layer+1, ans, returnColumnSizes);
    Traversal(root->right, layer+1, ans, returnColumnSizes);
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int layer = maxDepth(root);
    int** ans = malloc(layer * sizeof(int*));
    *returnSize = layer;
    
    for(int i=0; i<layer; i++){
        if(i<31)
            ans[i] = malloc((1<<i) * sizeof(int));
        else
            ans[i] = malloc(256 * sizeof(int));
    }
    
    (*returnColumnSizes) = calloc(layer, sizeof(int));
    
    Traversal(root, 0, ans, (*returnColumnSizes));
    
    
    return ans;
}