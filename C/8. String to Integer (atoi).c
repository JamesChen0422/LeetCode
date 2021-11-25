

int myAtoi(char * s){
    int flag=0, neg=0, ind=-1, i=0, res=0;
    char *new = malloc(strlen(s) * sizeof(char));
        
    for(int i=0; i<strlen(s); i++){   
        if(s[i]<'0' || s[i]>'9'){  
            if(flag)
                break;
            if((s[i]=='-' || s[i]=='+') && 
               (s[i+1]>='0' && s[i+1]<='9')){
                if(s[i]=='-') 
                    neg=1;                
                continue;
            } else if(s[i]==' ')   
                continue;
            else
                break;
        } else {   
            if(s[i]>='0' && s[i]<='9'){
                flag=1;
                ind++;
                new[ind]=s[i];
            }
        }            
    }
    
    if(ind==-1)
        return 0;
    
    while(i<=ind){
        if(neg && res>(INT_MAX/10))
            return INT_MIN;
        else if(res>(INT_MAX/10))
            return INT_MAX;
        
        res *= 10;
        if(res >= 2147483640){
            if(neg){
                if((new[i]-'0')>=8)
                    return INT_MIN;
            } else{
                if((new[i]-'0')>=7)
                    return INT_MAX;
            }
        }
            
        res += (new[i]-'0');
        i++;
    }
    

    return neg ? -res : res;        
}