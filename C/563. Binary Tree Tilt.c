
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int travel(struct TreeNode* root, int *ret)
{
    if(!root)
        return 0;
    int left=travel(root->left, ret);
    int right=travel(root->right, ret);
    *ret+=abs(left-right);
    return root->val + left + right;

}

int findTilt(struct TreeNode* root){
    int ret=0;
    travel(root, &ret);
    return ret;
}