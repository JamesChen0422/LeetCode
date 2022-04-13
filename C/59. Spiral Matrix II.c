

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    *returnSize = n;
    int** ans = malloc(n * sizeof(int*));
    *returnColumnSizes = malloc(n * sizeof(int));
    for(int i=0; i<n; i++){
        ans[i] = malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
    }
    
    int up = 0, down = n - 1, left = 0, right = n - 1, val = 1;
    
    while(1){
        for (int j = left; j <= right; ++j) 
            ans[up][j] = val++;
        if (++up > down) 
            break;       
        for (int i = up; i <= down; ++i) 
            ans[i][right] = val++;
        if (--right < left) 
            break;        
        for (int j = right; j >= left; --j)
            ans[down][j] = val++;
        if (--down < up)
            break;
        for (int i = down; i >= up; --i)
            ans[i][left] = val++;
        if (++left > right) 
            break;        
    }
    
    return ans;
}