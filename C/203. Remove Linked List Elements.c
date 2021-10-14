/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    if(!head)
        return head;
    
    struct ListNode* ans = malloc(sizeof(struct ListNode));
    struct ListNode* temp = ans;
    temp->next = head;
       
    while(temp->next){
        if(temp->next->val == val)
            temp->next=temp->next->next;
        else
            temp=temp->next;
    }
    
    return ans->next;
}