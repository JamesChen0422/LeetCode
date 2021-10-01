bool check(int* arr, int* subsetSum, bool* taken, int subset, int K, int N, int curIdx, int limitIdx)
{
    if (subsetSum[curIdx] == subset)
    {
        if (curIdx == K - 2)
            return true;
        
        return check(arr, subsetSum, taken, subset, K, N, curIdx + 1, N - 1);
    }
  
    for (int i = limitIdx; i >= 0; i--)
    {
        if (taken[i])
            continue;
        int tmp = subsetSum[curIdx] + arr[i];
  
        if (tmp <= subset)
        {
            taken[i] = true;
            subsetSum[curIdx] += arr[i];
            bool nxt = check(arr, subsetSum, taken, subset, K, N, curIdx, i - 1);
  
            taken[i] = false;
            subsetSum[curIdx] -= arr[i];
            if (nxt)
                return true;
        }
    }
    return false;
}


bool canPartitionKSubsets(int* nums, int numsSize, int k){
    int sum=0, max, group, temp=0;
    int *subsetSum = calloc(k, sizeof(int));
    bool taken[numsSize];
    
    if (k == 1)
        return true;
    
    if (numsSize < k)
        return false;
    
    for(int i=0; i<numsSize; i++){
        sum+=nums[i];
    }
    
    if(sum%k)
        return false;
    
    max=sum/k;
    group=(numsSize/k)+(numsSize%k);
    
    for(int i=0; i<numsSize; i++){
        if(nums[i]>max)
            return false;
    
    }
    
    for (int i = 0; i < k; i++)
        subsetSum[i] = 0;
  
    for (int i = 0; i < numsSize; i++)
        taken[i] = false;
  
    subsetSum[0] = nums[numsSize - 1];
    taken[numsSize - 1] = true;
  
    return check(nums, subsetSum, taken,
                                     max, k, numsSize, 0, numsSize - 1);

    
}