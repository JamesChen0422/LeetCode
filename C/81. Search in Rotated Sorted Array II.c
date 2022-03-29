

bool binarysearch(int* nums, int numsSize, int target){
    int start=0, end=numsSize-1, mid;
    
    while(start<=end){
        mid = start + (end-start)/2;
        if(nums[mid]>target)
            end=mid-1;
        else if(nums[mid]<target)
            start=mid+1;
        else
            return true;
    }        
    
    return false;
}

bool search(int* nums, int numsSize, int target){
    int *right = malloc(numsSize * sizeof(int));
    int i;
    
    for(i=0; i<numsSize; i++){
        right[i] = nums[i];
        if(i == numsSize-1 || nums[i+1] < nums[i])
            break;
    }
    
    if(target >= right[0])
        return binarysearch(right, i+1, target);
    
    int *left = malloc(numsSize * sizeof(int));
    int j;
    for(j=0; j<numsSize; j++){
        if(i+j+1 < numsSize)
            left[j] = nums[i+j+1]; 
        else
            break;         
    }  
    
    return binarysearch(left, j, target);
}

