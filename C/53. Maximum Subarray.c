

int maxSubArray(int* nums, int numsSize){
    int temp=0, max_sum=INT_MIN;
        
    for (int i=0; i<numsSize; i++) {
        if(temp+nums[i]>nums[i])
            temp+=nums[i];
        else
            temp=nums[i];
            
        if(temp>max_sum)    
            max_sum = temp;
    }
    
    return max_sum;
}