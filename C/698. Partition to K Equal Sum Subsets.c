
bool canPartitionKSubsets(int* nums, int numsSize, int k){
    int sum=0, max, group;
    for(int i=0; i<numsSize; i++){
        sum+=nums[i];
    }
    
    if(sum%k)
        return false;
    
    max=(sum/k)+1;
    group=numsSize/k;
    
    for(int i=0; i<numsSize; i++){
        if(nums[i]>max)
            return false;
        
    }
    
    return true;
    
}