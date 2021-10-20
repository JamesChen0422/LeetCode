

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int *ans = malloc(nums1Size * sizeof(int));
    for(int i=0; i<nums1Size; i++){
        for(int j=0; j<nums2Size; j++){
            if(nums2[j]==nums1[i]){
                if(j+1<nums2Size){
                    for(int k=j+1; k<nums2Size; k++){
                        if(nums2[k]>nums1[i]){
                            ans[i]=nums2[k];
                            break;
                        } else
                            ans[i]=-1;
                    }
                } else
                   ans[i]=-1;
                break;
            }
        }
    }
    
    *returnSize=nums1Size;
    return ans;
}