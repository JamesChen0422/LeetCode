/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void insert(struct TreeNode* root, int val){
    if(val > root->val){
        if(root->right)
            insert(root->right, val);
        else{
            root->right = malloc(sizeof(struct TreeNode));
            root->right->val = val;
            root->right->left = NULL;
            root->right->right = NULL;
        }            
    } else {
        if(root->left)
            insert(root->left, val);
        else{
            root->left = malloc(sizeof(struct TreeNode));
            root->left->val = val;
            root->left->left = NULL;
            root->left->right = NULL;
        }         
    }
}

struct TreeNode* insertIntoBST(struct TreeNode* root, int val){
    if(!root){
        struct TreeNode* res = malloc(sizeof(struct TreeNode));
        res->val = val;
        res->left = NULL;
        res->right = NULL;
        return res;
    }
    insert(root, val);
    
    return root;
}