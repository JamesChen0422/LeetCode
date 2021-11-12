

//Clockwise

#define SWAP(x,y) int temp=x; x=y; y=temp;

void reverse(int *matrix, int matrixSize){
    int head = 0, tail = matrixSize-1;
    
    while(head<tail){
        SWAP(matrix[head], matrix[tail]);
        head++, tail--;   
    }
}

void rotate(int** matrix, int matrixSize, int* matrixColSize){
    
    for(int i=0; i<matrixSize; i++){
        for(int j=i+1; j<(*matrixColSize); j++){
            SWAP(matrix[i][j], matrix[j][i]);
        }
        reverse(matrix[i], matrixSize);
    }  
}


===========================================================================


//Counterclockwise

#define SWAP(x,y) int temp=x; x=y; y=temp;

void reverse(int *matrix, int matrixSize){
    int head = 0, tail = matrixSize-1;
    
    while(head<tail){
        SWAP(matrix[head], matrix[tail]);
        head++, tail--;   
    }
}

void rotate(int** matrix, int matrixSize, int* matrixColSize){
    
    for(int i=0; i<matrixSize; i++){
        for(int j=0; j<(*matrixColSize)-i; j++){
            SWAP(matrix[i][j], matrix[matrixSize-1-j][matrixSize-1-i]);
        }
        reverse(matrix[i], matrixSize);
    }  
}