


typedef struct {
    int cnt;
    int val[30000];
} MinStack;


MinStack* minStackCreate() {
    MinStack* temp = malloc(sizeof(MinStack));
    temp->cnt = -1;
    
    return temp;
}

void minStackPush(MinStack* obj, int val) {
    obj->cnt += 1;
    obj->val[obj->cnt] = val;    
}

void minStackPop(MinStack* obj) {
    int temp=obj->val[obj->cnt];
    obj->cnt -= 1;
    return temp;
}

int minStackTop(MinStack* obj) {
    return obj->val[obj->cnt];
}

int minStackGetMin(MinStack* obj) {
    int min = INT_MAX;
    for(int i=0; i<=obj->cnt; i++){
        min = min < obj->val[i] ? min : obj->val[i];
    }
    return min;
}

void minStackFree(MinStack* obj) {
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/