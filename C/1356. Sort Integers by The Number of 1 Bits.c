struct Map{
    int bit[14];
    int arr[14][500];
};

int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int bits(int n){
    int cnt = 0;
    
    while(n){
        n &= n-1;
        cnt++;
    }
    
    return cnt;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortByBits(int* arr, int arrSize, int* returnSize){
    int* ans = malloc(arrSize * sizeof(int));
    struct Map* map = calloc(1, sizeof(struct Map));
    
    for(int i=0; i<arrSize; i++){
        int tmp = bits(arr[i]);
        map->arr[tmp][map->bit[tmp]++] = arr[i];        
    }
    
    *returnSize = 0;
    
    for(int i=0; i<=13; i++){
        qsort(map->arr[i], map->bit[i], sizeof(int), cmp);
        for(int j=0; j<(map->bit[i]); j++){
            ans[(*returnSize)++] = map->arr[i][j];
        }
    }
    
   
    return ans;
}


========================================================================================


int cmp(const void *a, const void *b){
{
    int abit = 0;
    int bbit = 0;
    int _a = *(int*)a;
    int _b = *(int*)b;
    
    while(_a){
        _a &= _a-1;
        abit++;
    }
    
    while(_b){
        _b &= _b-1;
        bbit++;
    }
    
    if(abit != bbit)
        return abit - bbit;
    else
        return *(int*)a - *(int*)b;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortByBits(int* arr, int arrSize, int* returnSize){

    qsort(arr, arrSize, sizeof(int), cmp);
    *returnSize = arrSize;
    return arr;
    
}