

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define SWAP(x,y) {int tmp=x; x=y; y=tmp;}

int* sortArrayByParity(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int head=0, tail=numsSize-1;
    
    while(head<tail){
        if((nums[head]%2!=0) && (nums[tail]%2==0)){
            SWAP(nums[head], nums[tail]);
            head++, tail--;
        } else if((nums[head]%2!=0) && (nums[tail]%2!=0))
            tail--;
        else if((nums[head]%2==0) && (nums[tail]%2==0))
            head++;
        else
            head++, tail--;
    }
    
    return nums;
}