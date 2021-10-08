

int fib(int n){
    if(n==0)
        return 0;
    else if(n==1 || n==2)
        return 1;
    else
        return fib(n-1)+fib(n-2);
    
}


=======================================================



int fib(int n){
    int* trib = (int*)malloc(3 * sizeof(int));
    trib[0]=0, trib[1]=1, trib[2]=1;
    
    if(n<3)
        return trib[n];
    
    for(int i=2; i<=n; i++){
        trib[2]=trib[0]+trib[1];
        trib[0]=trib[1];
        trib[1]=trib[2];
    }
    
    return trib[2];
}