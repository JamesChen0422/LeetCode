

bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity){
    int max, i, j;
    for(i = 0; i < tripsSize; i++){
        max = max > trips[i][2] ? max : trips[i][2];
    }
    
    int* map = calloc(max, sizeof(int));
    for(i = 0; i < tripsSize; i++){
        for(j = trips[i][1]; j < trips[i][2]; j++){
            map[j] += trips[i][0];
            if(map[j] > capacity)
                return false;
        }
    }
    
    return true;
}