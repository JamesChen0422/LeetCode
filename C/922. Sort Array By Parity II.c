/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int *ret =  malloc(sizeof(int)*numsSize);
    int even_position = 0;
    int odd_position = 1;
    
    for(int i=0; i<numsSize; i++){
        if(nums[i]%2==0){
            ret[even_position] = nums[i];
            even_position+=2;
        } else {
            ret[odd_position] = nums[i];
            odd_position+=2;
        }
    }
    
    return ret;
}