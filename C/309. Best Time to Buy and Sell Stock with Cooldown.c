
#define max(x,y) x>y ? x:y;

int maxProfit(int* prices, int pricesSize){
    int sold = 0;
    int rest = 0;
    int hold = INT_MIN;
    for (int i=0; i<pricesSize; i++) {
        int prev_sold = sold;
        sold = hold + prices[i];
        hold = max(hold, rest - prices[i]);
        rest = max(rest, prev_sold);
    }

    return max(rest, sold);
}


=======================================================


#define max(x,y) x>y ? x:y;

int maxProfit(int* prices, int pricesSize){
    int f[3] = {0,-prices[0],0};
    for (int i=1; i<pricesSize; i++){
        int t[3];
        t[0] = max(f[0], f[2]);
        t[1] = max(f[1], f[0]-prices[i]);
        t[2] = f[1] + prices[i];
        f=t;
    }
    return max(f[0], f[2]);
}