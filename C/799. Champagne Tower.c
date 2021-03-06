

double champagneTower(int poured, int query_row, int query_glass){
    double arr[100][100] = {0};
    arr[0][0] = poured;
    
     for (int i = 0; i < query_row; i++){
            for (int j = 0; j <= i; j++){
                arr[i + 1][j] += 0 < (arr[i][j] - 1.0) / 2.0 ? (arr[i][j] - 1.0) / 2.0 : 0;
                arr[i + 1][j + 1] += 0 < (arr[i][j] - 1.0) / 2.0 ? (arr[i][j] - 1.0) / 2.0 : 0;
            }
        }
        
        return arr[query_row][query_glass] < 1 ? arr[query_row][query_glass] : 1;
}