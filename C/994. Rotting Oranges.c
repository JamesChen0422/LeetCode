int infect(int i, int j, int rows, int cols, int** grid){
    if (i > 0 && grid[i-1][j] == 2) return 1;
    if (j > 0 && grid[i][j-1] == 2) return 1;
    if (i < rows-1 && grid[i+1][j] == 2) return 1;
    if (j < cols-1 && grid [i][j+1] == 2) return 1;
    return 0;
}

int orangesRotting(int** grid, int gridSize, int* gridColSize){
    int rot;
    int day = 0;
    int fresh;
    do {
        rot = 0;
        fresh = 0;
        for (int i = 0; i < gridSize; i++)
            for (int j = 0; j < gridColSize[i]; j++)
                if (grid[i][j] == 1)
                    if (infect(i, j, gridSize, gridColSize[i], grid)){
                        grid[i][j] = -1;
                        rot = 1;
                    } else {
                        fresh = 1;
                    }
        
        if (rot){
            day++;
            for (int i = 0; i < gridSize; i++)
                for (int j = 0; j < gridColSize[i]; j++)
                    if (grid[i][j] == -1) grid[i][j] = 2;
        }
        
    } while (rot);
    
    return fresh ? -1 : day;
}