

int cmp(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int twoCitySchedCost(int** costs, int costsSize, int* costsColSize){
    int* _cost = malloc(costsSize * sizeof(int));
    int  ans = 0;
    
    for(int i=0; i<costsSize; i++){
        ans += costs[i][0];
        _cost[i] = costs[i][1] - costs[i][0];
    }
    
    qsort(_cost, costsSize, sizeof(int), cmp);
    
    for(int i=0; i<costsSize/2; i++){
        ans += _cost[i];
    }
    
    return ans;
}