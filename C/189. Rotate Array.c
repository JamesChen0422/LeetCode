
void rotate(int* nums, int numsSize, int k){
    int* ans = malloc(sizeof(int)*numsSize);
    
    if(numsSize<2)
        return;
    
    if(k>numsSize)
        k%=numsSize;
    
    for(int i=0; i<numsSize; i++){
        if(i<k)
            ans[k-1-i] = nums[numsSize-1-i];
        else 
            ans[i] = nums[i-k];
    }
    
    while(numsSize){
        *(nums++)=*(ans++);
        numsSize--;
    }

}


==================================================


#define SWAP(x,y) int temp; temp = x; x=y; y=temp; 

void reverse(int* nums, int start, int end)
{
    while (start < end) {
        SWAP(nums[start], nums[end]);
        start++;
        end--;
    }
}

void rotate(int* nums, int numsSize, int k){
    if (k >= numsSize) {
        k %= numsSize;
    }
    
    if (k == 0) {
        return;
    }
    
    if(numsSize<2)
        return;
    
    reverse(nums, 0, numsSize-1);
    
    reverse(nums, 0, k-1);
    
    reverse(nums, k, numsSize-1);
}