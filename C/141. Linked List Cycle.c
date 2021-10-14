/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

bool hasCycle(struct ListNode *head) {
    struct ListNode * temp=head,*temp2=NULL;
    
    if(!head || !(head->next))
        return false;
    
    temp2=head->next;
    
    while(temp!=temp2)
    {
        if(temp2==NULL || temp2->next==NULL)
            return false;
       
        temp=temp->next;
        
        if(temp2->next->next)
            temp2=temp2->next->next;
        else
            return false;
    }
    
    return true;
}