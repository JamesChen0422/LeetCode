

bool validMountainArray(int* arr, int arrSize){
    bool inc = false, dec = false;
    for(int i = 0; i < arrSize-1; i++){
        if(arr[i] < arr[i+1]){
            if(dec) 
                return false;
            else 
                inc = true;
        } else if(arr[i] > arr[i+1]){
            if(!inc) 
                return false;
            else 
                dec = true;
        } else
            return false;
    }
    return inc && dec;
}