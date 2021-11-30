

void duplicateZeros(int* arr, int arrSize){
    int i=0;
    while(i<arrSize){
        if(arr[i]==0){
            for(int j=arrSize-2;j>=i; j--){
                arr[j+1] = arr[j];
            }
            arr[i] = 0;
            i++;
        }  
        i++;
    }
}