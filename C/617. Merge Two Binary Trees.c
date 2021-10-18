/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void merge(struct TreeNode* root1, struct TreeNode* root2){
    if(!root1 || !root2)
        return;
    
    if(root1 != root2 && root1 && root2)
        root1->val += root2->val;

    if(!(root1->left) && root2->left)
        root1->left = root2->left;
    if(!(root1->right) && root2->right)
        root1->right = root2->right;
   
    merge(root1->left, root2->left);
    merge(root1->right, root2->right);   
    return;
}

struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2){
    if(!root1 && root2)
        return root2;
    if(!root2 && root1)
        return root1;
    
    merge(root1, root2);
    return root1;
}

=================================================


struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2){
    if (!t2)
        return t1;
    if (!t1)
        return t2;
    t1->val += t2->val;
    t1->left = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t2->right);
    return t1;
}