

int islandPerimeter(int** grid, int gridRowSize, int* gridColSize){
    int peri=0;
    
    for(int i=0; i<gridRowSize; i++){
        for(int j=0; j<*gridColSize; j++){
            if(grid[i][j]){
                peri+=4;
                if(i+1<gridRowSize && grid[i+1][j])
                    peri-=2;
                if(j+1<*gridColSize && grid[i][j+1])
                    peri-=2;
            }
        }
    }
    
    return peri;   
}