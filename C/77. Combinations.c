

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void GetLineSize(int **res, int *line, int lineSize,int n, int k, int *resLen, int idx)
{
    if (lineSize == k) {
        res[*resLen] = (int *)malloc(sizeof(int) * k);
        memcpy(res[*resLen], line, sizeof(int) * k);
        (*resLen) = (*resLen) + 1;
        return;
    }

    for (int i = idx; i <= n; i++) {
        line[lineSize] = i;
        GetLineSize(res, line, lineSize + 1, n, k, resLen, i + 1);
    }
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes){

    int **res = (int **)malloc(sizeof(int *)* 10000);
    int line[100];
    int lineSize = 0;
    int resLen = 0;
    GetLineSize(res, line, lineSize, n, k, &resLen, 1);
    *returnSize = resLen;
    *returnColumnSizes=malloc(sizeof(int)*(*returnSize));
    int i=*returnSize-1;
    while(i>=0){
    	(*returnColumnSizes)[i--]=k;
    }
    return res;
    
}