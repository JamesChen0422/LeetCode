/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize){
    struct ListNode **ans = malloc(sizeof(struct ListNode) * k);
    struct ListNode *temp = head, *temp1=NULL, *temp2=NULL;
    int cnt=0, quot, rem, i, j;    
    while(temp!=NULL){
        temp = temp->next;
        cnt++;
    }
    
    quot=cnt/k, rem=cnt%k;
    temp=head;
    
    
    for (i=0 ; i<k ; i++) {
        temp1=calloc(1, sizeof(struct ListNode)), temp2=temp1;
        for(j=0; j< quot + (i<rem ? 1:0); j++){
            temp2->next = malloc(sizeof(struct ListNode));
            temp2=temp2->next;
            temp2->val = temp->val;
            temp2->next = NULL;           

            if(temp!=NULL)
                temp=temp->next;
        }
        ans[i]=temp;
    }

    *returnSize = k;

    return ans;
}


=================================================================


struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize){
    struct ListNode **ans = malloc(sizeof(struct ListNode) * k);
    struct ListNode *temp = head, *temp1=NULL, *temp2=NULL;
    int cnt=0, quot, rem, i, j;    
    while(temp!=NULL){
        temp = temp->next;
        cnt++;
    }
    
    quot=cnt/k, rem=cnt%k;
    temp=head;
    
    
    for (i=0 ; i<k ; i++) {
        ans[i] = temp;
        if(temp){
            for(j=quot + (i<rem ? 1:0); j>1; j--){            
                temp=temp->next;
            }
            head = temp->next;
            temp->next = NULL;
            temp = head;   
        }
    }   
    
    *returnSize = k;

    return ans;
}


==================================================================


struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize){
    struct ListNode **ans = malloc(sizeof(struct ListNode) * k);
    struct ListNode *h = head, *c = head, *p = NULL;
    int cnt, i, j, l;    
    for (cnt = 0 ; h ; cnt++)
        h = h->next;
    
    j=cnt/k, l=cnt%k;

    for (i=0 ; i<k ; i++) {
        ans[i] = c;
        for (int n = j+(l ? !!l-- : 0); c && n ; n--)
            p = c, c = c->next;
        p ? p->next = NULL : 0;
    }
    *returnSize = k;
    return ans;
}