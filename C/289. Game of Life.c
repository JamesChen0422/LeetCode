int value(int **board, int i, int j, int m, int n)
{
    if (i >= 0 && i < m && j >= 0 && j < n) {
        switch (board[i][j]) {
            case 2:
                return 1;
            case 3:
                return 0;
            default:
                return board[i][j];
        }
    }
    return 0;
}

void update_value(int ** b, int i, int j, int m, int n)
{
    int count;
    
    count = value(b, i-1, j-1, m , n) +
            value(b, i-1, j, m, n) +
            value(b, i-1, j +1, m, n) +
            value(b, i, j -1, m, n) +
            value(b, i, j + 1, m, n) +
            value(b, i+1, j -1, m, n) +
            value(b, i+1, j, m, n) +
            value(b, i+1, j + 1, m, n);
    
    if (b[i][j] == 1 && (count < 2 || count > 3))
            b[i][j] = 2;
    else if (b[i][j] == 0 && count == 3)
            b[i][j] = 3;
}

void gameOfLife(int** board, int boardSize, int* boardColSize){
    
    int m = boardSize, n = *boardColSize;
    
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            update_value(board, i, j,m, n);
    
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            if (board[i][j] > 1)
                board[i][j] -= 2;
        }
}