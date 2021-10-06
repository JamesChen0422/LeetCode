
bool containsDuplicate(int* nums, int numsSize){
    int *value = malloc(sizeof(int)*numsSize);
    int not_dup = 1;
    *value = *nums;
    
    for(int i=1; i<numsSize; i++){ 
        for(int j=0; j<not_dup; j++){
            if(*(nums+i)==*(value+j))
               return true;            
        }
        *(value+not_dup)=*(nums+i);
        not_dup++;
    }
               
    return false;
}


==============================================================


int compare(const void *a, const void *b){
    return *(const int *)a - *(const int *)b;
}

bool containsDuplicate(int* nums, int numsSize){
    qsort (nums, numsSize, sizeof(int), compare);
    
    for (int i=1; i<numsSize; i++) {
        if (nums[i]==nums[i-1])
            return true;
    }
    return false;
}