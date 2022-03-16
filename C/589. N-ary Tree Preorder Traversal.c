/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void preorderTraversal(struct Node* root, int* result, int* returnSize){
    if(!root) 
        return;
    
    result[(*returnSize)++]=root->val;
    for(int i=0; i<root->numChildren; i++)
        preorderTraversal(root->children[i], result, returnSize);
}

int* preorder(struct Node* root, int* returnSize) {
    int *result = (int*)malloc(10000*sizeof(int));
    *returnSize = 0;
        
    preorderTraversal(root, result, returnSize);
    
    return result;
}