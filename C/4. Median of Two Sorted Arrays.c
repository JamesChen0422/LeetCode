

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int len = nums1Size + nums2Size;
    int mid = len/2;
    int sort[mid+1];
    int i = 0, j = 0;   
    
    for(int index=0; index<=mid; index++){
        if(i>=nums1Size)
            sort[index] = nums2[j++];
        else if(j>=nums2Size)
            sort[index] = nums1[i++];
        else if(nums1[i]<nums2[j])
            sort[index] = nums1[i++];
        else
            sort[index] = nums2[j++];
    }
    
    if(len%2)
        return sort[mid];
    else
        return (sort[mid-1]+sort[mid]) / (double)2;
}