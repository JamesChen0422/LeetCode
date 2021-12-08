

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int len = nums1Size > nums2Size ? nums1Size : nums2Size;
    int *nums = calloc(1001, sizeof(int));
    int *inter = calloc(len, sizeof(int));
    *returnSize = 0;
    
    for(int i=0; i<nums1Size; i++){
        if(!nums[nums1[i]])
            nums[nums1[i]]++;
    }
    
    for(int i=0; i<nums2Size; i++){
        if(nums[nums2[i]] == 1)
            nums[nums2[i]]++;
    }
    
    for(int i=0; i<1001; i++){
        if(nums[i] == 2)
            inter[(*returnSize)++]=i;            
    }  
    return inter;
}