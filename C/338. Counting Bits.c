

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize){
    *returnSize = n+1;
    int* ans = calloc(n+1, sizeof(int));
    ans[0] = 0; 
    for(int i=1; i<=n; i++){
        int tmp = i;
        int cnt = 0;
        while(tmp){
            tmp &= (tmp-1);
            cnt++;
        }        
        ans[i] = cnt;
    }
    
    return ans;
}