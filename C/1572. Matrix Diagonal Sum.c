

int diagonalSum(int** mat, int matSize, int* matColSize){
    int sum = 0;
    
    for(int i=0; i<matSize; i++){
        if(i != matSize-i-1)
            sum += (mat[i][i] + mat[i][matSize-i-1]);
        else 
            sum += mat[i][i];
    }   
    
    return sum;
}


======================================================================


int diagonalSum(int** mat, int matSize, int* matColSize){
    int sum = 0;
    
    for(int i=0; i<matSize; i++){
        sum += (mat[i][i] + mat[i][matSize-i-1]);           
    }
    
    if(matSize%2 != 0){
        int tmp = matSize/2;
        sum -= mat[tmp][tmp];
    }
    
    return sum;
}
