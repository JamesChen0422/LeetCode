
int cmp (const void * a, const void * b) {
   return ( *(int*)b - *(int*)a );
}

int numRescueBoats(int* people, int peopleSize, int limit){
    qsort(people, peopleSize, sizeof(int), cmp);
    int cnt = 0, idx = peopleSize-1;
    
    for(int i=0; i<peopleSize; i++){
        if(people[i] == 0)
            break;
        
        if(people[i] == limit)
            cnt++;
        else{  
            if(i<idx && people[i]+people[idx] <= limit){
                people[idx] = 0;
                idx--;
                cnt++;
            } else
                cnt++;
        }
    }    
    
    return cnt;
}


============================================================================



int cmp (const void * a, const void * b) {
   return ( *(int*)b - *(int*)a );
}

int numRescueBoats(int* people, int peopleSize, int limit){
    qsort(people, peopleSize, sizeof(int), cmp);
    int cnt = 0, start = 0, end = peopleSize-1;
    
    while(start <= end){        
        if(people[start]+people[end] <= limit){
            start++;
            end--;
        } else
            start++;
        cnt++;
    }    
    
    return cnt;
}