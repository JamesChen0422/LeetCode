
int removeDuplicates(int* nums, int numsSize){
    int position=1;
    int count=0;
     
    if (numsSize == 0) { return 0;}
    
    for(int i=1; i<numsSize; i++){
        if(nums[i]!=nums[i-1]){
            nums[position]=nums[i];
            position++;
            count=0;
        } else if(nums[i]==nums[i-1] && count<1){
            nums[position]=nums[i];
            position++;
            count++;
        } 
    }
    return position;
}