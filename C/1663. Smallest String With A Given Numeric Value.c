

char * getSmallestString(int n, int k){
    char* ans = malloc((n+1) * sizeof(char));
    memset(ans, 'a', n);
    ans[n] = '\0';
    
    k -= n;
    while (k) {
      int tmp = k<25 ? k:25;
      ans[--n] += tmp;
      k -= tmp;
    }
    
    return ans;
}