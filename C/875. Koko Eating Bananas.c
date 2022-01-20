

int minEatingSpeed(int* piles, int pilesSize, int h){
    int left = 1, right = 1e9;
    while (left < right) {
        int mid = left + (right - left) / 2, cnt = 0;
        for (int i=0; i<pilesSize; i++) 
            cnt += (piles[i] + mid - 1) / mid;
        if (cnt > h) 
            left = mid + 1;
        else 
            right = mid;
    }
    return right;
}