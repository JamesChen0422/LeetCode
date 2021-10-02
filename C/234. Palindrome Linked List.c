/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* rev = NULL;
    while(head!=NULL){
        struct ListNode* new = (struct ListNode*)malloc(sizeof(struct ListNode));
        new->val = head->val;
        new->next= rev;
        rev = new;

        head = head->next;
    }
    
    return rev;
}

bool isPalindrome(struct ListNode* head){
    struct ListNode* temp = head, *rev;
    int cnt=0, half=0;
    
    
    while(head){
        cnt++;
        head = head->next;        
    }
    
    if(cnt == 1)
        return true;
    
    head = temp;
    
    if(cnt%2){
        half = (cnt/2) - 1;
        while(half){
            half--;
            head = head->next;
        }
    } else {
         half = (cnt/2);
         while(half){
            half--;
            head = head->next;
         }
    }
    
    rev = reverseList(head);
    
    head = temp;   
    
    for(int i=0; i<cnt/2; i++){
        printf("%d %d \n", head->val, rev->val);
        if(head->val != rev->val)
            return false;
        head = head->next;
        rev = rev->next;
    }
    
    return true;
    
}


====================================================


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* rev = NULL;
    
    while(head!=NULL){
        struct ListNode* new = (struct ListNode*)malloc(sizeof(struct ListNode));
        new->val = head->val;
        new->next= rev;
        rev = new;

        head = head->next;
    }
    
    return rev;
}

bool isPalindrome(struct ListNode* head){
    struct ListNode* temp = head, *rev;
    
    rev = reverseList(head);
    
    while(head){
        if(head->val != rev->val)
            return false;
        head = head->next;
        rev = rev->next;
    }       
    
    return true;
    
}