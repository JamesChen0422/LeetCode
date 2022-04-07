

int cmp(const void* a, const void* b){
    return *(int*)a-*(int*)b;
}

int binarySearch(int* arr, int l, int r, int x, int set)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;
        
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x, set);
        
        return binarySearch(arr, mid + 1, r, x, set);
    }
    
    return set;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * idxote: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int idx = 0;
    int allocated = numsSize * 2;
    int **res = (int **)malloc(allocated * sizeof(int *));
    *returnSize = 0;

    if (numsSize < 3)
        return res;
    
    qsort(nums, numsSize, sizeof(*nums), cmp);
    int k = numsSize;
    for (int i = 0; i < numsSize && nums[i] <= 0; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            int search = -(nums[i] + nums[j]);
            if (search < 0)
                break;
            
            k = binarySearch(nums, j + 1, numsSize - 1, search, numsSize);
            if (k < numsSize) {
                res[idx] = malloc(sizeof(int) * 3);
                res[idx][0] = nums[i];
                res[idx][1] = nums[j];
                res[idx][2] = nums[k];
                idx++;

                if (j == i + 1)
                    numsSize = k;
                
                if (idx == allocated) {
                    allocated *= 2;
                    res = (int **)realloc(res, allocated * sizeof(int *));
                }
            } 
        
            while (j + 1 < numsSize && nums[j] == nums[j + 1])
                j++;
        }
       
        while (i + 1 < numsSize && nums[i] == nums[i + 1])
            i++;
    }
    
    *returnSize = idx;
    *returnColumnSizes = malloc(idx * sizeof(int));    
    for (int i = 0; i < idx; i++)
        (*returnColumnSizes)[i] = 3;
    
    return res;
}