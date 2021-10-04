

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    int temp;
    
    for(int i=0; i<9; i++){
         for(int j=0; j<9; j++){
             temp=board[i][j];
             
             if(temp=='.')
                 continue;
             
             for(int k=i+1; k<9; k++){
                 if(board[k][j]==temp)
                     return false;                 
             }
             
             for(int k=j+1; k<9; k++){
                 if(board[i][k]==temp)
                     return false;
             }
             
             int cnt=0;
             for(int sub_row=0; sub_row<3; sub_row++){
                 for(int sub_col=0; sub_col<3; sub_col++){
                    if(board[sub_row+i-i%3][sub_col+j-j%3]==temp)
                        cnt++;
                    if(cnt>1)
                        return false;  
                 }
             }             
         }       
    }
    
    return true;
}