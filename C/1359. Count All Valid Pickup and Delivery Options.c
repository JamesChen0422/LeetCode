

int countOrders(int n){
    int M = 1000000007;
    long long int ans = 1;

    for(int i=1; i<n+1; i++){
        ans = (ans*i*(2*i-1))%M;
    }
    
    return ans%M;    
}


==================================================================


int countOrders(int n){
    long long int ans = 1;
    
    for(int i=1; i<n+1; i++){
        ans = (ans*i*(2*i-1))%1000000007;
    }
    
    return ans%1000000007;    
}