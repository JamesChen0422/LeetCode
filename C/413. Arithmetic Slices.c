

int numberOfArithmeticSlices(int* nums, int numsSize){
    int* diff = malloc((numsSize-1) * sizeof(int));
    for(int i=0; i<numsSize-1; i++){
        diff[i] = nums[i+1] - nums[i];
    }
    int cnt = 1, res = 0;
    for(int i=1; i<numsSize-1; i++){
        if(diff[i] == diff[i-1])
            cnt++;
        else{
            if(cnt>2)
                res += ((cnt-1)*cnt)/2;
            else if(cnt == 2)
                res += 1;
            cnt = 1;
        }        
    }
    if(cnt>2)
        res += ((cnt-1)*cnt)/2;
    else if(cnt == 2)
                res += 1;
            
    return res;
}


====================================================================




int numberOfArithmeticSlices(int* nums, int numsSize){
    int* diff = malloc((numsSize-1) * sizeof(int));
    for(int i=0; i<numsSize-1; i++){
        diff[i] = nums[i+1] - nums[i];
    }
    int cnt = 0, res = 0;
    for(int i=1; i<numsSize-1; i++){
        if(diff[i] == diff[i-1])
            cnt++;
        else{
            if(cnt>0)
                res += ((cnt+1)*cnt)/2;
            cnt = 0;
        }        
    }
    if(cnt>0)
        res += ((cnt+1)*cnt)/2;
    
    return res;
}