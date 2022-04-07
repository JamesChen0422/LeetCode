

int cmp(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int lastStoneWeight(int* stones, int stonesSize){
    if(stonesSize == 1)
        return *stones;
    
    qsort(stones, stonesSize, sizeof(int), cmp);
    
    while(stones[stonesSize-2] != 0 && stonesSize){
        if(stones[stonesSize-2] == stones[stonesSize-1])
            stones[stonesSize-1] = 0, stones[stonesSize-2] = 0;
        else
            stones[stonesSize-1] -= stones[stonesSize-2], stones[stonesSize-2] = 0;
        qsort(stones, stonesSize, sizeof(int), cmp);
    }
    
    return stones[stonesSize-1];
}