
char * addBinary(char * a, char * b){
    int max = strlen(a) > strlen(b) ? strlen(a) : strlen(b);
    char *ans = (char *)malloc(sizeof(char)*(max+2));
    int i, j, k, sum = 0;    
    ans[max+1] = '\0';
    
    for(i = strlen(a)-1, j=strlen(b)-1, k=max; i >= 0 || j >= 0; i--, j--, k--){
        sum += i>=0 ? a[i]-'0' : 0;
        sum += j>=0 ? b[j]-'0' : 0;
        ans[k] = sum%2 == 0 ? '0' : '1';
        sum = sum>=2 ? 1 : 0;
    }
    
    if(sum){
        ans[k] = '1';
        return ans;
    } else
        return ans+1; 
}