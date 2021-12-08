
typedef struct {
    int *arr;
} MyHashSet;

MyHashSet* myHashSetCreate() {
    MyHashSet* tmp = calloc(1, sizeof(MyHashSet));
    tmp->arr = calloc(1000001, sizeof(int));
    return tmp;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    obj->arr[key] = 1;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    obj->arr[key] = 0;
}

bool myHashSetContains(MyHashSet* obj, int key) {
    return obj->arr[key];
}

void myHashSetFree(MyHashSet* obj) {
    free(obj->arr);
    free(obj);
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 
 * myHashSetRemove(obj, key);
 
 * bool param_3 = myHashSetContains(obj, key);
 
 * myHashSetFree(obj);
*/