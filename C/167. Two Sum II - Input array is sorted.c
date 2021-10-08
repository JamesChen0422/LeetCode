/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize=2;
    int *ans=malloc(sizeof(int)*2);
    
    for(int i=0; i<numsSize; i++)
         for(int j=i+1; j<numsSize; j++)
            if(nums[i]+nums[j]==target)
                ans[0]=i+1, ans[1]=j+1;       
    
    return ans;
}


===================================================


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize=2;
    int *ans=malloc(sizeof(int)*2);
    int head=0, tail=numsSize-1;
   
    while(head<tail){
        if(nums[head]+nums[tail] == target){
            ans[0]=head+1, ans[1]=tail+1;
            return ans;
        } else if(nums[head]+nums[tail] > target)
            tail--;
        else
            head++;
    }    
   
    return NULL;
}