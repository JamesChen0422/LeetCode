/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* insert(struct TreeNode* root, int val){
    if(root == NULL)
    {
        struct TreeNode *newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    else
    {
        if(root->val > val)
        {
             root->left = insert(root->left,val);
        }
        else
        {
            root->right = insert(root->right,val);
        }
    }
    return root;
}

struct TreeNode* bstFromPreorder(int* preorder, int preorderSize){
    struct TreeNode *root = NULL;
    
    
    for(int i = 0;i < preorderSize;i++)
    {
        root = insert(root,preorder[i]);
    }
    return root;
}


=========================================================================


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* newTreeNode(int val){
    struct TreeNode* result = malloc(sizeof(struct TreeNode));
    result->val = val;
    result->left = NULL;
    result->right = NULL;
    return result;
}

void insert(struct TreeNode** root, struct TreeNode* newTreeNode){
    if (*root!=NULL){
        if (newTreeNode->val > (*root)->val){
            if ((*root)->right == NULL){
                (*root)->right = newTreeNode;
            }
            else{
                return insert(&((*root)->right), newTreeNode);
            }
        }
        else{
            if ((*root)->left == NULL){
                (*root)->left = newTreeNode;
            }
            else{
                return insert(&((*root)->left), newTreeNode);
            }
        }
    }
    else{
        (*root) = newTreeNode;
    }
}



struct TreeNode* bstFromPreorder(int* preorder, int preorderSize){
    int n = preorderSize;
    struct TreeNode* result = NULL;
    struct TreeNode* current;
    for (int i = 0; i<n ; i++){
        current = newTreeNode(preorder[i]);
        insert(&result, current);
    }
    return result;
}