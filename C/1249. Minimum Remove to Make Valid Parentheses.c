

char * minRemoveToMakeValid(char * s){
    int i, idx=0;
    int left=0, right=0;
    char* ans=malloc((strlen(s)+1) * sizeof(char));
    strcpy(ans, s);

    for(i=strlen(s)-1; i>=0; i--){
        if(ans[i] == ')') 
            right++;
        if(ans[i] == '(') 
            left++;
        if(left>right){
            ans[i]=0;   
            left--;     
        }
    }
    
    left=right=0;
    
    for(i=0; i<strlen(s); i++){
        if(ans[i] == ')') 
            right++;
        if(ans[i] == '(') 
            left++;
        if(right>left){
            right--;          
        } else if(ans[i]){                
          ans[idx++]=ans[i]; 
        }
    }
    
    ans[idx] = '\0';
    
    return ans;
}