

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MIN(x,y) (x<y ? x:y)

void dp(int **ret, int h, int w)
{
    int i, j;

    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++){
            if (i > 0)
                ret[i][j] = MIN(ret[i][j], ret[i - 1][j] + 1);
            if (j > 0)
                ret[i][j] = MIN(ret[i][j], ret[i][j - 1] + 1);
        }
    }

    for (i = h - 1; i >= 0; i--) {
        for (j = w - 1; j >= 0; j--) {
            if (i + 1 < h)
                ret[i][j] = MIN(ret[i][j], ret[i + 1][j] + 1);
            if (j + 1 < w)
                ret[i][j] = MIN(ret[i][j], ret[i][j + 1] + 1);
        }
    }
}

int** updateMatrix(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes){
   int h = matSize;
    int w = matColSize[0];

    int **ret = malloc(sizeof(int *) * h);
    int i, j;
    for (i = 0; i < h; i++) {
        ret[i] = malloc(sizeof(int) * w);  
    }

    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            if (!mat[i][j])
                ret[i][j] = 0;
            else
                ret[i][j] = 100000;
        }
    }

    dp(ret, h, w);

    *returnSize = matSize;
    *returnColumnSizes = matColSize;
    return ret;  
}