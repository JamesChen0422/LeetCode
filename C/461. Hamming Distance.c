
int hammingDistance(int x, int y){
    int count=0;
    x ^= y;
    
    while(x){
        x &= (x-1);
        count++;
    }
    
    return count;
}