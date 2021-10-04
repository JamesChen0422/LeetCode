/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    
    struct ListNode* ans = malloc(sizeof(struct ListNode));
    struct ListNode* temp = &ans;
    
    if (l1 == NULL && l2 == NULL)
        return NULL;
    
    while (l1 && l2) {
        if (l1->val < l2->val) {
            temp->next = l1;
            l1 = l1->next;
            temp = temp->next;
        } else {
            temp->next = l2;
            l2 = l2->next;
            temp = temp->next;
        }
    }

    if (l1) {
        temp->next = l1;
    }
    if (l2) {
        temp->next = l2;
    }
  
    return ans->next;

}