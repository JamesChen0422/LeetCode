

int startValue(int* nums, int numsSize, int tmp){
    int sum = tmp;
    for(int i=0; i<numsSize; i++){
        sum+=nums[i];        
        if(sum < 1)
            return startValue(nums, numsSize, tmp+1);
    }
    
    return tmp;
}

int minStartValue(int* nums, int numsSize){
    int value;
    
    value = startValue(nums, numsSize, 1);
    
    return value;
}