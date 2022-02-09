

int compare(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}


int findPairs(int* nums, int numsSize, int k){
    qsort(nums , numsSize, sizeof(int), compare);
    int cnt=0, tmp;
    for(int i=0; i<numsSize; i++){
        for(int j=i+1; j<numsSize; j++){
            if(nums[i]==tmp)
                continue;
            if((nums[j]-nums[i])==k){
                cnt++;
                tmp = nums[i];
                i++;
            }
        }
    }
    
    return cnt;
}