
int maxProfit(int* prices, int pricesSize){
    int profit=0;    

    for (int i = 0; i < pricesSize-1; ++i) {
        if (prices[i] < prices[i+1]) {
            profit += prices[i+1] - prices[i];
        }
    }
    return profit;
}


====================================================



int maxProfit(int* prices, int pricesSize){
    int cost=0;
    bool buy;
    int profit=0;
    
    if(pricesSize==0)
        return 0;
    
    for(int i=1; i<pricesSize; i++){        
        if(buy){
            if(prices[i]<prices[i-1]){
                profit+=(prices[i-1]-cost);
                buy=false;
            } else if(i==pricesSize-1){
                profit+=(prices[i]-cost);
            }
        } else if(prices[i]>prices[i-1]){
            cost=prices[i-1];
            buy=true;
            if(i==pricesSize-1){
                profit+=(prices[i]-cost);
            }
        }         
    }
    
    return profit;
}