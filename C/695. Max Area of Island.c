#define MAX(a,b) (((a) > (b)) ? (a) : (b))

int visit(int **grid, int gridSize, int gridColSize, int i, int j)
{
    if (i < 0 || i >= gridSize)
        return 0;
    if (j < 0 || j >= gridColSize)
        return 0;
    if (grid[i][j] == 0)
        return 0;
    
    grid[i][j] = 0;
    int cnt = 1;
    cnt += visit(grid, gridSize, gridColSize, i+1, j);
    cnt += visit(grid, gridSize, gridColSize, i-1, j);
    cnt += visit(grid, gridSize, gridColSize, i, j+1);
    cnt += visit(grid, gridSize, gridColSize, i, j-1);
    return cnt;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize)
{
    int i, j;
    int largest = -1;
    
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridColSize[0]; j++) {
            int c = visit(grid, gridSize, gridColSize[0], i, j);
            largest = MAX(largest, c);
        }
    }
    
    return largest;
}