#define MAX(x,y) x > y ? x : y

int deleteAndEarn(int* nums, int numsSize){
    int earn = 0, delete = 0, max = 0;
    int* sums = calloc(10001, sizeof(int));
    
    for (int i = 0; i < numsSize; i++){
        sums[nums[i]] += nums[i];
        max = MAX(max, nums[i]);
    }
    
    for (int i = 0; i <= max; i++){
        int _earn = delete + sums[i];
        int _delete = MAX(delete, earn);
        earn = _earn; delete = _delete;
    }
    
    return MAX(earn, delete); 
}


=======================================================


#define MAX(x,y) x > y ? x : y

int deleteAndEarn(int* nums, int numsSize){
    int earn = 0, delete = 0, max = 0;
    int* sums = calloc(10001, sizeof(int));
    
    for (int i = 0; i < numsSize; i++){
        sums[nums[i]] += nums[i];
        max = MAX(max, nums[i]);
    }
    
    for (int i = 2; i < 10001; ++i) {
        sums[i] = MAX(sums[i - 1], sums[i - 2] + sums[i]);
    }
    
    return sums[10000];
  
}