

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int size = (nums1Size>nums2Size ? nums2Size : nums1Size);
    int *ans = malloc(sizeof(int)*size);
    int temp=0;
    
    for(int i=0; i<nums1Size; i++){
        for(int j=0; j<nums2Size; j++){
            if(*(nums1+i)==*(nums2+j)){
                *(ans+temp)=*(nums2+j);
                *(nums2+j)=-1;
                temp++;
                break;
            }
        }
    }
    
    *returnSize = temp;

    return ans;
}