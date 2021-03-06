

bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize){    
    if (coordinatesSize == 2) 
        return true;
        
    int x = 2;
    int y = 2; 
    int cordX = coordinates[1][0] - coordinates[0][0];
    int cordY = coordinates[1][1] - coordinates[0][1];
        
    for (int i = 2; i < coordinatesSize; i++) {
        if (coordinates[i][0] - coordinates[i - 1][0] == cordX)
            x++;
        if (coordinates[i][1] - coordinates[i - 1][1] == cordY)
            y++;
    }
    if (x == coordinatesSize && y == coordinatesSize) return true;

    for (int i = 0, j = 1, k = 2; i < coordinatesSize - 2; i++, j++, k++) {
        if ((coordinates[i][1] - coordinates[j][1]) *
                (coordinates[i][0] - coordinates[k][0]) !=
                (coordinates[i][1] - coordinates[k][1]) *
                (coordinates[i][0] - coordinates[j][0])) return false;
    }
    
    return true;
}