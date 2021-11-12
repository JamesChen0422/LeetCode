

int reverse(int x){
    int tmp=0, ans=0, flag=0;
    if(x>0)
        flag = 1;          
    
    while(x!=0){  
        if(flag){
            if(ans > INT_MAX/10)
                return 0;
        } else{
            if(ans < INT_MIN/10)
                return 0;
        }
        tmp = x % 10;
        ans = ans*10 + tmp;     
        x /= 10;
    }    
    
    return ans; 
}