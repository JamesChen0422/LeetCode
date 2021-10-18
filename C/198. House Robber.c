
#define max(x,y)  x > y ? x : y ;

int rob(int* nums, int numsSize){
    int robEven = 0, robOdd = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (!(i%2)) {
            robEven = max(robEven + nums[i], robOdd);
        } else {
            robOdd = max(robEven, robOdd + nums[i]);
        }
    }
    return max(robEven, robOdd);
}