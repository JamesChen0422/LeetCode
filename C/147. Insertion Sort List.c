/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* insertionSortList(struct ListNode* head){
    struct ListNode* ans = malloc(sizeof(struct ListNode));
    ans->val = -1;
    ans->next = NULL;
    struct ListNode* cur = ans;
    
    while (head) {
        struct ListNode *tmp = head->next;
        cur = ans;
        while (cur->next && cur->next->val <= head->val) {
            cur = cur->next;
        }
        head->next = cur->next;
        cur->next = head;
        head = tmp;
    }
    return ans->next;
}