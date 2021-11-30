

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* replaceElements(int* arr, int arrSize, int* returnSize){
    *returnSize = arrSize;
    for(int i=0; i<arrSize; i++){
        int max=-1;
        for(int j=i+1; j<arrSize; j++){
            max = max>arr[j] ? max : arr[j];
        }
        arr[i]=max;
    }
    return arr;
}