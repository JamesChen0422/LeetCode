/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct {
    int* node;
    int len;
    int idx;
} BSTIterator;

void inorder(struct TreeNode* root, int* node, int* len) {
    if(root == NULL) return;
    
    inorder(root->left, node, len);
    node[(*len)++] = root->val;
    inorder(root->right, node, len);
}

BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator* new = malloc(sizeof(BSTIterator));
    new->node = malloc(100000 * sizeof(int));
    new->len = 0;
    new->idx = 0;
    
    inorder(root, new->node, &new->len);
    
    return new;
}

int bSTIteratorNext(BSTIterator* obj) {
    return obj->node[obj->idx++];
}

bool bSTIteratorHasNext(BSTIterator* obj) {
    return obj->idx < obj->len;
}

void bSTIteratorFree(BSTIterator* obj) {
    free(obj->node);
    free(obj);
}

/**
 * Your BSTIterator struct will be instantiated and called as such:
 * BSTIterator* obj = bSTIteratorCreate(root);
 * int param_1 = bSTIteratorNext(obj);
 
 * bool param_2 = bSTIteratorHasNext(obj);
 
 * bSTIteratorFree(obj);
*/