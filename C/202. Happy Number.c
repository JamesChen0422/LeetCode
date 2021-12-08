
//Time Limit Exceeded
bool isHappy(int n){
    int *digits = calloc(10, sizeof(int));
    int sum;

repeat:
    sum=0;
    if(n>6){
        while(n){
            digits[n%10]=1;
            n/=10;        
        }
        for(int i=1; i<10; i++){
            if(digits[i])
                sum+=(i*i);
            digits[i]=0;
        }
        n=sum;
        goto repeat;
    } 
    
    return n==1;
}


=====================================================================


bool isHappy(int n){
    int *table = calloc(731, sizeof(int));
    
    while(n != 1)
    {
        int tmp = n;
        n = 0;
        while(tmp)
        {
            n += (tmp%10)*(tmp%10);
            tmp/=10;
        }
        table[n]++;
        if (table[n] == 2)
            return false;
    }
    return true;
}