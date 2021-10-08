

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes){
    
    if(r*c != matSize * (*matColSize)){
        r = matSize;
        c = *matColSize;
    }
        
        
    *returnSize = r;
    int** ans = (int**)malloc(r * sizeof(int*));    
    *returnColumnSizes = (int*)malloc(r * sizeof(int));
    
    for(int i = 0; i < r; i++){
        *(ans+i) = (int*)malloc(sizeof(int)*c);
        *(*returnColumnSizes+i) = c;
    }
    
    for(int i = 0; i < matSize * (*matColSize); i++)
        ans[i/c][i%c] = mat[i/(*matColSize)][i%(*matColSize)];
    
    return ans;   
}