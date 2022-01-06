

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


===============================================================




bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity){
    int map[1001] = {0};

    for(int i = 0; i < tripsSize; i++) {
        
        map[trips[i][1]] += trips[i][0];
        map[trips[i][2]] += -trips[i][0];
        
    }


    int curr = 0;
    for(int i = 0; i < 1001; i++) {
        
        curr += map[i];
        if(curr > capacity) {
            
            return false;
        }
    }

    return true;
}