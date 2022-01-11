/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */



typedef struct {
    int num;
    struct ListNode *node;
} Solution;


Solution* solutionCreate(struct ListNode* head) {
    Solution* create = malloc(sizeof(Solution));
    struct ListNode* tmp = head;
    int cnt = 0;
    
    while(tmp){
        tmp = tmp->next;
        cnt++;
    }
    
    create->num = cnt;
    create->node = head;
    
    return create; 
}

int solutionGetRandom(Solution* obj) {
    int random = rand() % obj->num;
    struct ListNode* tmp = obj->node;
    
    while(random){
        tmp = tmp->next;
        random--;
    }
    
    return tmp->val;
}

void solutionFree(Solution* obj) {
    free(obj->node);
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(head);
 * int param_1 = solutionGetRandom(obj);
 
 * solutionFree(obj);
*/


====================================================


