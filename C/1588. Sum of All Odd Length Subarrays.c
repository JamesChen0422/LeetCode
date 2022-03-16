

int sumOddLengthSubarrays(int* arr, int arrSize){
    int result = 0, sum = 0;
    int n = arrSize;

    for(int i = 0;i < arrSize; i++){
        sum = 0;
        int start  = n-i;
        int end = i+1;
        int total = start*end;
        int odd = total/2;
        
        if (total%2){
            odd++ ;
        }
        
        sum = arr[i]*odd;
        result += sum;
    }
    
    return result;
}