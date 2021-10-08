

int tribonacci(int n){
    int* trib = (int*)malloc(4 * sizeof(int));
    trib[0]=0, trib[1]=1, trib[2]=1;
    
    if(n<3)
        return trib[n];
    
    for(int i=3; i<=n; i++){
        trib[3]=trib[0]+trib[1]+trib[2];
        trib[0]=trib[1];
        trib[1]=trib[2];
        trib[2]=trib[3];
    }
    
    return trib[3];
}