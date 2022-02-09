/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void tree2arr(struct TreeNode* root, int* arr, int* len){
    if(!root)
        return;
    
    tree2arr(root->left, arr, len);
    
    arr[*len] = root->val;
    *len +=1;    

    tree2arr(root->right, arr, len);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getAllElements(struct TreeNode* root1, struct TreeNode* root2, int* returnSize){
    int* arr1 = malloc(5000 * sizeof(int));
    int* arr2 = malloc(5000 * sizeof(int));
    int len1 = 0, len2 = 0, i = 0, j = 0;
        
    tree2arr(root1, arr1, &len1);
    tree2arr(root2, arr2, &len2);
    
    *returnSize = len1+len2;
    int* ans = malloc((*returnSize) * sizeof(int));
    
    for(int index = 0; index < *returnSize; index++){
        if(i >= len1)
            ans[index] = arr2[j++];
        else if(j >= len2)
            ans[index] = arr1[i++];
        else if(arr1[i] < arr2[j])
            ans[index] = arr1[i++];
        else
            ans[index] = arr2[j++];
    }
    
    return ans;
}