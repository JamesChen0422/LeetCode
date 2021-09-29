
int removeElement(int* nums, int numsSize, int val){
    int length = numsSize, target = 0;
    for (int i=0; i < numsSize; i++) {
        if (nums[i] == val) {
            length--;
            target++;
        }
        else if (nums[i] !=val) {
            nums[i-target] = nums[i];
        }
    }
    
    return length;    
}