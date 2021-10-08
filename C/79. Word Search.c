

bool search(int row, int col, char** board, int boardSize, int* boardColSize, char * word, int match){
    
    if(match==strlen(word))
        return true;
    
    if (row < 0 || row >= boardSize)
        return false;
    
    if (col < 0 || col >= *boardColSize)
        return false;
    
    if (board[row][col] != word[match])
        return false;
    
    char temp = word[match];
    
    board[row][col] = NULL;
    match++;
    if(search(row-1, col, board, boardSize, boardColSize, word, match))
        return true;
    if(search(row, col-1, board, boardSize, boardColSize, word, match))
        return true;
    if(search(row+1, col, board, boardSize, boardColSize, word, match))
        return true;
    if(search(row, col+1, board, boardSize, boardColSize, word, match))
        return true;
    
    board[row][col] = temp;
    return false;
    
}

bool exist(char** board, int boardSize, int* boardColSize, char * word){
        
    for(int row=0; row<boardSize; row++)
        for(int col=0; col<*boardColSize; col++)
            if(board[row][col]==word[0])
                if(search(row, col, board, boardSize, boardColSize, word, 0))
                    return true;    
    
    return false;
}


=======================================================================