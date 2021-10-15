

bool isValid(char * s){
    if(strlen(s)%2)
        return false;
    
    char *stack=malloc((strlen(s)/2) * sizeof(char));    
    int idx = 0;
       
    for(int i=0; i<strlen(s); i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            if(idx==strlen(s)/2)
                return false;
            stack[idx++]=s[i];            
        } else {
            if(!idx)
                return false;
            if(abs(s[i]-stack[idx-1])>3)
                return false;
            else 
                idx--;
        }                
    }
    
    free(stack);
    return idx==0;
}