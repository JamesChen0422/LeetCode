
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    int cnt=0, mid;
    struct ListNode* temp=head;
    
    while(head){
        cnt++;
        head = head->next;
    }
    
    head=temp;
    mid = cnt/2;
            
    while(head){
        if(!mid)
            break;
        head = head->next; 
        mid--;
    }
    
    return head;
}