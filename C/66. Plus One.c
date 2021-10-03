/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int* ans = malloc(sizeof(int)*digitsSize);
      
    *(digits+digitsSize-1)+=1;
    
    for(int i=digitsSize-1; i>=0; i--){        
        if(i==0 && digits[i]==10){
            int* ans = malloc(sizeof(int)*(digitsSize+1));
            *ans = 1;
            for(int j=0; j<digitsSize; j++){
                *(ans+j+1) = *(digits+j)%10;
            }
            *returnSize = digitsSize+1;
            return ans;
        } else if(digits[i]<10){
            int* ans = malloc(sizeof(int)*digitsSize);
            ans = digits;
            *returnSize = digitsSize;
            return ans;
        } else {
            *(digits+i)=0;
            *(digits+i-1)+=1;
           
        }        
    }
    
    return ans;
    
}