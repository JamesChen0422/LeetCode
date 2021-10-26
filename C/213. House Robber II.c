
int rob(int* nums, int numsSize){
     if(numsSize <=3){
        int max = 0;
        for(int i=0; i<numsSize; i++)
            max = max < nums[i] ? nums[i] : max;
        return max;
    }
    int* sum = (int*)calloc(numsSize, sizeof(int));
    sum[0] = nums[0];
    sum[1] = nums[1] > nums[0] ? nums[1] : nums[0];
    for(int i=2; i<numsSize-1; i++)
        sum[i] = sum[i-2] + nums[i] < sum[i-1] ? sum[i-1] : sum[i-2] + nums[i];
    
    int temp = sum[numsSize - 2];
    sum[1] = nums[1];
    sum[2] = nums[2] > nums[1] ? nums[2] : nums[1];
    for(int i=3; i<numsSize; i++)
        sum[i] = sum[i-2] + nums[i] < sum[i-1] ? sum[i-1] : sum[i-2] + nums[i];
    return sum[numsSize-1] < temp ? temp : sum[numsSize-1];
}

