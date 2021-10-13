/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int layer(struct TreeNode* root){
    if(root)
        return layer(root->left)>layer(root->right) ? (layer(root->left)+1) : (layer(root->right)+1);
    else
        return 0;
}


void Traversal(struct TreeNode* root, int** ans, layer){
    if(root){

    }

}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    if(!root)
        return root;
    
    *returnSize = layer(root);
    int** ans = (int**)malloc(*returnSize * sizeof(int*);
    int layer_cnt=1;                          
    for(int i=0; i<layer){
        *(*returnColumnSizes+i) = malloc(layer_cnt * sizeof(int));
        layer_cnt*=2;
    }
    
    Traversal(root, ans, 0, 0);
        
    return ans;
}