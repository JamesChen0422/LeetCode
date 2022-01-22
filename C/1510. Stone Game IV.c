

bool winnerSquareGame(int n){
    int* dp = calloc(n+1, sizeof(int));
    
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k * k <= i; k++) {
            if (!dp[i - k * k]) {
                dp[i] = 1;
                break;
             }
         }
     }
    
     return dp[n];
}