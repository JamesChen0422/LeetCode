

void sortColors(int* nums, int numsSize){
    int color[3]={0};
    if(numsSize<2)
        return nums;
    
    for(int i=0; i<numsSize; i++){
        color[nums[i]]++;
    }
    for(int i=0; i<numsSize; i++){
        if(color[0]>0){
            nums[i] = 0;
            color[0]--;
        } else if(color[1]>0){
            nums[i] = 1;
            color[1]--;
        } else
            nums[i] = 2;
    }
}