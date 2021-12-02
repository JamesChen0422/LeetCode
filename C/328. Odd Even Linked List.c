/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head){
    if(!head || !(head->next))
        return head;
    struct ListNode* odd = head;
    struct ListNode* even = head->next;
    
    while(even && even->next){
        struct ListNode *tmp = odd->next;
        odd->next = even->next;
        even->next = even->next->next;
        odd->next->next = tmp;
        even = even->next;
        odd = odd->next;
    }
    return head;
}