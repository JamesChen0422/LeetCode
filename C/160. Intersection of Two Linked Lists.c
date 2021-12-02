/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *tmpA = headA;
    while(tmpA){
        struct ListNode *tmpB = headB;
        while(tmpB){
            if(tmpA == tmpB)
                return tmpA;
            tmpB = tmpB->next;
        }
        tmpA = tmpA->next;
    }
    return NULL;
}


============================================================================

//better speed implement
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* ptr1=headA;
    struct ListNode* ptr2=headB;
    while(ptr1 != ptr2){ 
        if(!ptr1) ptr1=headB; 
        else ptr1=ptr1->next;

        if(!ptr2) ptr2=headA;
        else ptr2=ptr2->next;
    }

    return ptr1; 
}