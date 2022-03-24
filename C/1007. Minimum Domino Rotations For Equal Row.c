

int swap_domino(int* dest, int* src, int size, int target){
    int cnt = 0;
    for(int i=0; i<size; i++){
        if(dest[i] != target){
            if(src[i] != target)
                return -1;
            else 
                cnt++;
        }
    }
    
    return cnt;
}

int minDominoRotations(int* tops, int topsSize, int* bottoms, int bottomsSize){
    int* top_cnt = calloc(6, sizeof(int));
    int* bot_cnt = calloc(6, sizeof(int));
    
    for(int i=0; i<topsSize; i++){
        top_cnt[tops[i]-1]++;
        bot_cnt[bottoms[i]-1]++;
    }
    
    for(int i=0; i<6; i++){
        if(top_cnt[i]+bot_cnt[i] >= topsSize){
            if(top_cnt[i]>bot_cnt[i])
                return swap_domino(tops, bottoms, topsSize, i+1);
            else 
                return swap_domino(bottoms, tops, topsSize, i+1);
        }
    }    
    
    return -1;
}