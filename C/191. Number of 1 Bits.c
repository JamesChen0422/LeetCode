

int hammingWeight(uint32_t n) {
    int weight=0;
    for(int i=0; i<32; i++){
        if(n>>i & 0x1)
            weight++;
    }
    return weight;
}


=========

int hammingWeight(uint32_t n) {
    int count=0;
    
    while(n){
        n &= (n-1);
        count++;
    }
    
    return count;
}

