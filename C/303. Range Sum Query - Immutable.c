


typedef struct {
    int *arr;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* new = malloc(sizeof(NumArray));
    new->arr = nums;
    
    return new;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    int sum = 0;
    for(int i=left; i<=right; i++){
        sum += obj->arr[i];
    }
    return sum;
}

void numArrayFree(NumArray* obj) {
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/


======================================================================





typedef struct {
    int *arr;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* new = malloc(sizeof(NumArray));
    new->arr = malloc((numsSize+1)*sizeof(int));
    new->arr[0] = 0;
    
    for(int i=0; i<numsSize; i++){
        new->arr[i+1] = nums[i] + new->arr[i]; 
    }
    
    return new;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    return obj->arr[right+1] - obj->arr[left];
}

void numArrayFree(NumArray* obj) {
    free(obj->arr);
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/