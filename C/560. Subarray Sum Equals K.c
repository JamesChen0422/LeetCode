

int subarraySum(int* nums, int numsSize, int k){
    int cnt = 0, sum = 0;
    int m[20000000] = {0};
    m[10000000] = 1;
    for (int i=0; i<numsSize; i++) {
        sum += nums[i];
        cnt += m[sum - k + 10000000];
        m[sum + 10000000]++;
    }
    
    return cnt;
}