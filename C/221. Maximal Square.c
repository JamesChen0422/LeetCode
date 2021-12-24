

int maximalSquare(char** matrix, int matrixSize, int *matrixColSize){       int max = 0;
                                                                     
    for (int j = 0; j < *matrixColSize; ++j) {
        matrix[0][j] -= '0';
        if (matrix[0][j] == 1) {
            max = 1;
        }
    }
                                                                     
    for (int i = 1; i < matrixSize; ++i) {
        for (int j = 0; j < *matrixColSize; ++j) {
            matrix[i][j] -= '0';
            if (matrix[i][j] != 0) {
                matrix[i][j] += matrix[i - 1][j];
            }
        }
        int count = 0;
        for (int k = 0; k < *matrixColSize; ++k) {
            if (matrix[i][k] > max) {
                ++count;
                if (count > max) {
                    ++max;
                    break;
                }
            } else {
                    count = 0;
            }
        }
    }
  
    return max * max;
}