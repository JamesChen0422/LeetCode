
bool Palindrome(char* s, int start, int end){
    while(start<end){
        if(s[start] == s[end]){
            start++, end--;
        } else 
            return false;            
    }
    
    return true;
}

char * longestPalindrome(char * s){
    int i, j;
    int len = strlen(s);
    
    for(i=len; i>1; i--){
        for(j=0; j+i<=len; j++){
            if(Palindrome(s, j, i+j-1)){
                goto result;
            } 
        }
    }
    
result:  ;
    char* ans = malloc((i+1) * sizeof(int));
    strncpy(ans, s+j, i);
    ans[i] = '\0';  
    return ans;
}


==============================================================


char * longestPalindrome(char * s){
    char *start, *end;
    char *p = s, *sub_start=s;
    int max_len = 1;
    while(*p) {
        start = p;
        end = p;
        while(*(end + 1) && *(end + 1) == *end)
            end++;
        p = end + 1;
        while(*(end + 1) && start > s && *(end + 1) == *(start - 1)){
            end++;
            start--;
        }
        if(end - start + 1 > max_len){
            max_len = end - start + 1;
            sub_start = start;
        }
    }
    char *ret = (char *)calloc(max_len + 1, sizeof(char));
    strncpy(ret, sub_start, max_len);
    return ret;
}