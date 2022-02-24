//Time Limit Exceeded
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#define SWAP(x, y) {int temp = x; x = y; y = temp;}

struct ListNode* sortList(struct ListNode* head){
    struct ListNode* tmp = head;
    bool swap = false;
again:
    while(tmp && tmp->next){
        if(tmp->val > tmp->next->val){
            SWAP(tmp->val, tmp->next->val);
            swap = true;
        }        
        tmp = tmp->next;
    }
    tmp = head;
    if(swap){
        swap = false;
        goto again;
    }
    
    return head;
}


===================================================================================

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int cmp (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

struct ListNode* sortList(struct ListNode* head) {
    int count = 0;
    struct ListNode* tmp = head;
    while(tmp!=NULL)
    {
        tmp = tmp->next;
        count++;
    }
    int *array = malloc(count*sizeof(int));
    tmp = head;
    count = 0;
    while(tmp!=NULL)
    {
        array[count] = tmp->val;
        tmp = tmp->next;
        count++;
    }
    qsort(array,count,sizeof(int),cmp);
    tmp = head;
    count = 0;
    while(tmp!=NULL)
    {
        tmp->val = array[count];
        tmp = tmp->next;
        count++;
    }
    return head;
}