

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
    int* fib = (int*)malloc(3 * sizeof(int));
    fib[0]=0, fib[1]=1, fib[2]=1;
    
    if(n<3)
        return fib[n];
    
    for(int i=2; i<=n; i++){
        fib[2]=fib[0]+fib[1];
        fib[0]=fib[1];
        fib[1]=fib[2];
    }
    
    return fib[2];
}