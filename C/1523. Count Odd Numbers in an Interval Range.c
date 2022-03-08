

int countOdds(int low, int high){
    int cnt = (high-low);
    if(cnt%2 == 0)
        if(low%2 == 0)
            return cnt/2;
    
    return cnt/2+1;
}