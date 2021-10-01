/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
*/
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* rev = NULL;
    while(head!=NULL){
        struct ListNode* new = (struct ListNode*)malloc(sizeof(struct ListNode));
        new->val = head->val;
        new->next= rev;
        rev = new;

        head = head->next;
    }
    
    return rev;
}