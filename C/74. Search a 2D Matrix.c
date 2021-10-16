

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int start=0, end=(matrixSize*(*matrixColSize))-1, mid;
    
    while(start<=end){
        mid = start + (end-start)/2;
        if(matrix[mid/(*matrixColSize)][mid%(*matrixColSize)]>target)
            end=mid-1;
        else if(matrix[mid/(*matrixColSize)][mid%(*matrixColSize)]<target)
            start=mid+1;
        else
            return true;
    }        
    
    return false;   
}