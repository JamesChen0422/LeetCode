

int findMaxConsecutiveOnes(int* nums, int numsSize){
    int max=0, tmp=0;
    for(int i=0; i<numsSize; i++){
        if(nums[i])
            tmp++;
        else{
            max = max>tmp ? max:tmp;
            tmp=0;
        }
    }
    
    return max>tmp ? max:tmp;
}