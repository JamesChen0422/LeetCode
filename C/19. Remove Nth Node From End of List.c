/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int cnt=0;
    int *ans=head;
      
    while(head){
        cnt++;
        head=head->next;
    }
    
    head=ans;
    
    if(cnt==1){
       return NULL;
    }
    
    while(head){
        cnt--;
        if(cnt<n && n>1){
            head->val = head->next->val;
            head->next = head->next->next;
            break;
        } else if(cnt<n+1 && n==1){
            head->next = NULL;
            break;
        } else {
            head = head->next;
        }
    }
    
    return ans;
}