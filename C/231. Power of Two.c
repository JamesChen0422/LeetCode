

bool isPowerOfTwo(int n){
    if(n<1)
        return false;
    int cnt=0;
    for(int i=0; i<32; i++){
        if(n>>i & 0x1)
            cnt++;
        if(cnt>1)
            return false;
    }

    return true;
}