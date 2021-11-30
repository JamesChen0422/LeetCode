
//Time Limit Exceeded
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    int* res = malloc(numsSize * sizeof(int));    
    int count=1, index=0;
    
    
    while(count<=numsSize){
        bool flag = false;
        for(int i=0; i<numsSize; i++){
            if(nums[i]==count){
                flag = true;
                break;
            }
        }
        if(flag){
            count++;
            continue;
        } else{
            res[index] = count;
            index++;
            count++;
        }
    }
    
    *returnSize = index;
    return res;
}


======================================================================


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    int* res = malloc(numsSize * sizeof(int));   
    int tmp=0;
    
    for (int i = 0; i < numsSize; i++){
        int index = abs(nums[i])-1;
        if(nums[index] > 0){
            nums[index] = (-nums[index]);
        }
    }

    for (int i = 0; i < numsSize; i++){
        if (nums[i] > 0){
            res[tmp++]=(i + 1);
        }
    }

    *returnSize = tmp;
    return res;
}
