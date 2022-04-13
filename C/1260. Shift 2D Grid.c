

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** shiftGrid(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes){
    *returnSize = gridSize;
    *returnColumnSizes = malloc(gridSize*sizeof(int));
    for(int i=0; i<gridSize; i++){
        (*returnColumnSizes)[i] = *gridColSize;
    }

    while(k){        
        int tmp = grid[gridSize-1][(*gridColSize)-1];
        for(int i = gridSize-1; i>=0; i--){
             for(int j = (*gridColSize)-1; j>=0; j--){
                 if(j)
                    grid[i][j] = grid[i][j-1];
                 else if(i && !j)
                    grid[i][j] = grid[i-1][(*gridColSize)-1];
                 else
                    grid[i][j] = tmp;
             }
        }
        k--;
    }

    return grid;
}