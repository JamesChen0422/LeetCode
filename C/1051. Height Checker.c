

int compare(const void *a, const void *b){
    return *(const int *)a - *(const int *)b;
}

int heightChecker(int* heights, int heightsSize){
    int* tmp = malloc(heightsSize * sizeof(int));
    int count=0;
    
    memcpy(tmp, heights, heightsSize * sizeof(int));
    
    qsort(heights, heightsSize, sizeof(int), compare);
    
    for(int i=0; i<heightsSize; i++){
        if(heights[i] != tmp[i])
            count++;
    }
    
    return count;
}