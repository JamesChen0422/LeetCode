/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    if (head == NULL || head->next == NULL)
        return head;  
    
    struct ListNode* ans = head->next, *prev = head, *temp;
    
    while(head && head->next){
        temp = head->next->next;
        prev->next = head->next;
        head->next->next = prev = head;
        head->next = temp;
        head = head->next;
    }
    
    return ans;
}