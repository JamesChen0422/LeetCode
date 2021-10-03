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
        if(temp2==NULL)
        {
            return false;
        }
        temp=temp->next;
        if(temp2->next && temp2->next->next)
            temp2=temp2->next->next;
        else
            temp2 = temp2->next;
    }
    
    return true;
}