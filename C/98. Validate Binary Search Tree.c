/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool Valid(struct TreeNode* root, long min, long max){
    if(!root)
        return true;
    else{                
        if(root->val > min && root->val < max)
            return Valid(root->left, min, root->val) && Valid(root->right, root->val, max);
        else
            return false;
    }
}

bool isValidBST(struct TreeNode* root){
    
    return Valid(root, -2147483649, 2147483648);           
}