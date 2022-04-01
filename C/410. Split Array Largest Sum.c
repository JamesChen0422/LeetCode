#define MAX(x,y) x > y ? x : y

bool can_split(int* nums, int numsSize, int m, int sum) {
    int cnt = 1, curSum = 0;
    for (int i = 0; i < numsSize; i++) {
        curSum += nums[i];
        if (curSum > sum) {
            curSum = nums[i];
            cnt++;
            if (cnt > m) 
                return false;
        }
    }
    
    return true;
}

int splitArray(int* nums, int numsSize, int m){
    int left = 0, right = 0;
    for (int i = 0; i < numsSize; ++i) {
        left = MAX(left, nums[i]);
        right += nums[i];
    }
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (can_split(nums, numsSize, m, mid)) 
            right = mid;
        else 
            left = mid + 1;
    }
    
    return right;
}