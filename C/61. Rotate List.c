
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
    if(!head)
        return head;
    
    int count=1, rotate;
    struct ListNode* tmp = head, *ans;
    
    while(tmp->next){
        tmp = tmp->next;
        count++;
    }
    rotate = k % count;
    count -= rotate;
    
    tmp->next = head;
    
    while(count){
        tmp = tmp->next;
        count--;
    }
    ans = tmp->next;
    tmp->next = NULL;
    
    return ans;
}