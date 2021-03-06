

int threeSumMulti(int* arr, int arrSize, int target){
    int i, j, k, c1, c2, c3;
    int cnt[101] = {0};
    long long  sum = 0;
    
    for (i = 0; i < arrSize; i++) {
        cnt[arr[i]]++;
    }
    
    for (i = 0; i < 101; i++) {
        if ((c1 = cnt[i]) == 0) {
            continue;
        }
        
        for (j = i; j < 101 && (k = target-i-j) >= j; j++) {
            if (k > 100 || (c2 = cnt[j]) == 0 || (c3 = cnt[k]) == 0) {
                continue;
            }

            if (i == j && i == k) {
                sum += (long long) c1 * (c2 - 1) * (c3 - 2) / 6;
            } else if (i == j) {
                sum += (long long) c1 * (c2 - 1) * c3 / 2;
            } else if (i == k || j == k) {
                sum += (long long) c1 * c2 * (c3 - 1) / 2;
            } else {
                sum += (long long) c1 * c2 * c3;
            }
            
            sum %= 1000000007;
        }
    }
    
    return sum;
}