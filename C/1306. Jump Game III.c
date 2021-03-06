
bool canReach(int* arr, int arrSize, int start){
    if(start >= arrSize || start < 0 || arr[start] == INT_MAX)
        return false;
    if(arr[start] == 0) return true;
    int step = arr[start];
    arr[start] = INT_MAX;
    bool left = canReach(arr, arrSize, start + step);
    bool right = canReach(arr, arrSize, start - step);
    arr[start] = step;
    return left || right;
}