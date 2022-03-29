

int findDuplicate(int* nums, int numsSize){
    int* map = calloc((numsSize-1), sizeof(int));
    int i;
    for(i=0; i<numsSize; i++){
        map[nums[i]-1]++;
        if(map[nums[i]-1]>1)
            break;
    }
    
    return nums[i];
}