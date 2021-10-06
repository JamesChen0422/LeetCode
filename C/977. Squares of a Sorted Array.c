int compare(const void *a, const void *b){
    return *(const int *)a - *(const int *)b;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize){
    *returnSize=numsSize;
    
    for(int i=0; i<numsSize; i++)
        nums[i]*=nums[i];
    
    qsort(nums, numsSize, sizeof(int), compare);
    
    return nums;
}