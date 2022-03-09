/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode* ans = malloc(sizeof(struct ListNode));
    ans->next = head;
    struct ListNode* cur = ans;

    while(head){
        if(head->next && (head->val == head->next->val)){
            while(head->next && (head->val == head->next->val))
                head = head->next;
            cur->next = head->next; 
        } else
            cur = cur->next;
        
        head = head->next;
    }
    
    return ans->next;
}


==============================================================================


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head == NULL)
        return NULL;
    struct ListNode *tmp, *next, **cur;
    cur = &head;
    int num;
    while(*cur){
        tmp = *cur;
        num = 0;
        for(next = tmp->next; next != NULL && tmp->val == next->val; next = next->next)
            num++;
        if(num != 0)
            *cur = next;
        else
            cur = &(tmp->next);
    }

    return head;
}