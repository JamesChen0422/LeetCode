int comp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int majorityElement(int* nums, int numsSize){
    int i;
    int cnt = 0;
    int maj = numsSize / 2;
    
    qsort (nums, numsSize, sizeof(int), comp);
    
    for (i = 1 ; i < numsSize; i++) {
        if (nums[i] != nums[i-1]) {
            cnt = 1;
        }
        else if (nums[i] == nums[i-1]) {
            cnt++;
        }
        
        if (cnt > maj)
            return nums[i];
    }
    
    return nums[0];
}