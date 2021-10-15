


typedef struct {
    int stack1[100];
    int stack1_idx;
    int stack2[100];
    int stack2_idx;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* que = malloc(sizeof(MyQueue));
    que->stack1_idx = -1;
    que->stack2_idx = -1;
    return que;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->stack1[++obj->stack1_idx] = x;   
}

int myQueuePop(MyQueue* obj) {
    if (obj->stack2_idx == -1)
        while (obj->stack1_idx >= 0)
            obj->stack2[++obj->stack2_idx] = obj->stack1[obj->stack1_idx--];
    return obj->stack2[obj->stack2_idx--];
}

int myQueuePeek(MyQueue* obj) {
    if (obj->stack2_idx == -1)
        while (obj->stack1_idx >= 0)
            obj->stack2[++obj->stack2_idx] = obj->stack1[obj->stack1_idx--];
    return obj->stack2[obj->stack2_idx];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->stack1_idx == -1 && obj->stack2_idx == -1;
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/