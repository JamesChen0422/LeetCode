/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int Cousins(struct TreeNode* root, int target, int* parent){
    if(!root)
        return 0;
    
    if(root->val == target)
        return 1;
    
    if(Cousins(root->left, target, parent)){
        *parent=root->val;
        return 1+Cousins(root->left, target, parent);
    } else if(Cousins(root->right, target, parent)){
        *parent=root->val;
        return 1+Cousins(root->right, target, parent);
    }
    
    return 0;
}

bool isCousins(struct TreeNode* root, int x, int y){
    int depth_x=0, depth_y=0, parent_x, parent_y;
    depth_x = Cousins(root, x, &parent_x);
    depth_y = Cousins(root, y, &parent_y);
    
    return depth_x==depth_y && parent_x!=parent_y;
}