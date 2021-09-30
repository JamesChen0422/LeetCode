not finish


bool canPartitionKSubsets(int* nums, int numsSize, int k){
    int sum=0, max, group, temp;
    for(int i=0; i<numsSize; i++){
        sum+=nums[i];
    }
    
    if(sum%k)
        return false;
    
    max=(sum/k)+1;
    group=(numsSize/k)+(numsSize%k);
    
    for(int i=0; i<numsSize; i++){
        if(nums[i+1]<nums[i]){
            temp=nums[i];
            nums[i]=nums[i+1];
            nums[i+1]=temp;
        }
    }

    for(int i=0; i<numsSize; i++){
        if(nums[i]>max)
            return false;
    
    }
    
    return true;
    
}