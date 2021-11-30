


int findNumbers(int* nums, int numsSize){
    int count=0;
    for(int i=0; i<numsSize; i++){
        int digit=0;
        while(nums[i]){
            nums[i] /= 10;
            digit++;
        }
        if(digit%2==0)
            count++;
    }
    return count;
}