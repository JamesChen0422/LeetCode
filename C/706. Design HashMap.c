


typedef struct {
    int *arr;
} MyHashMap;


MyHashMap* myHashMapCreate() {
    MyHashMap* obj = calloc(1, sizeof(MyHashMap));
    obj->arr = malloc(1000001 * sizeof(int));
    memset(obj->arr, -1, 1000001 * sizeof(int));
    return obj;
}

void myHashMapPut(MyHashMap* obj, int key, int value) {
    obj->arr[key] = value;
}

int myHashMapGet(MyHashMap* obj, int key) {
    return obj->arr[key];
}

void myHashMapRemove(MyHashMap* obj, int key) {
    obj->arr[key] = -1;
}

void myHashMapFree(MyHashMap* obj) {
    free(obj->arr);
    free(obj);
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);
 
 * int param_2 = myHashMapGet(obj, key);
 
 * myHashMapRemove(obj, key);
 
 * myHashMapFree(obj);
*/