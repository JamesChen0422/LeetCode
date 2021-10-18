/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define swap(x,y) {struct TreeNode *temp; temp=x, x=y, y=temp;}

struct TreeNode* invertTree(struct TreeNode* root){
    if(!root)
        return root;
    
    if(root->left && root->right){
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
    } else if(root->left && !(root->right)){
        root->right = root->left;
        root->left = NULL;
        invertTree(root->right);
    } else{
        root->left = root->right;
        root->right = NULL;
        invertTree(root->left);
    }
    
    return root;
}


========================================================


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define swap(x,y) {struct TreeNode *temp; temp=x, x=y, y=temp;}

struct TreeNode* invertTree(struct TreeNode* root){
    if(root){  
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);    
    }
    
    return root;
}