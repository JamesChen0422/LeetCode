

int compare(const void *a, const void *b){
    return *(const int *)a - *(const int *)b;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize){
    int *ans = malloc(sizeof(int)*numsSize);
    int cnt=0;
    qsort(nums, numsSize, sizeof(int), compare);
    
    for (int i=1; i<numsSize; i++) {
        if (nums[i]==nums[i-1]){
            ans[cnt]=nums[i];
            cnt++;
        }
    }
    
    *returnSize=cnt;
    return ans;
}