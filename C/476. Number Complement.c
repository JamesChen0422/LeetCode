

int findComplement(int num){
    int tmp = num, c = 0;
    while(tmp>0){
        c = (c << 1) | 1;
        tmp >>= 1;
    }  
    return num ^ c;
}