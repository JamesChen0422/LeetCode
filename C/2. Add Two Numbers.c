struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode ans;
    ans.val = 0; ans.next = NULL;
    struct ListNode* l3 = &ans;
    int remainder = 0, sum;
    while (l1 != NULL || l2 != NULL || remainder != 0) {
        sum = remainder + (l1 == 0 ? 0 : l1->val) + (l2 == 0 ? 0: l2->val);
        remainder = sum/10;
        sum %= 10;
        l3->next = malloc(sizeof(struct ListNode));
        l3->next->next = NULL;
        l3->next->val = sum;
        l3 = l3->next;
        l1 = (l1 == 0 ? 0 : l1->next);
        l2 = (l2 == 0 ? 0 : l2->next);
    }
    return ans.next;
}


=====================================================


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* l1_out = l1;
    struct ListNode* l2_out = l2;
    int data=0;
    bool is_l1 = true;
    
    while(l1!=NULL || l2!=NULL){ 
        if(l1!=NULL && l2!=NULL){
            data = l1->val + l2->val;
            l1->val = data%10;
            l2->val = data%10;
            if(data/10 && l1->next!=NULL)
                l1->next->val += data/10;
            else if(data/10 && l2->next!=NULL)
                l2->next->val += data/10;
            else if(data/10){
                l1->next = malloc(sizeof(struct ListNode));
                l1->next->next = NULL;
                l1->next->val = data/10;
            }
            l1=l1->next;
            l2=l2->next;
        } else if(l1!=NULL && l2==NULL){
            data = l1->val;
            l1->val = data%10;
            if(data/10 && l1->next==NULL){
                l1->next = malloc(sizeof(struct ListNode));
                l1->next->next = NULL;
                l1->next->val = data/10;
            } else if(data/10 && l1->next->val!=NULL)
                l1->next->val += data/10;              
            l1=l1->next;
        } else if(l1==NULL && l2!=NULL){
            data = l2->val;
            l2->val = data%10;
            if(data/10 && l2->next==NULL){
                l2->next = malloc(sizeof(struct ListNode));
                l2->next->next = NULL;
                l2->next->val = data/10;
            } else if(data/10 && l2->next->val!=NULL)
                l2->next->val += data/10;              
            l2=l2->next;
            is_l1=false;
        } 
    }
    
    return is_l1 ? l1_out : l2_out;
}