int cmp(const void *a, const void *b)
{      
     return *(int *)a - *(int *)b;                          
}

double average(int* salary, int salarySize){
    qsort(salary, salarySize, sizeof(int), cmp);
    double total;    
    for(int i=1; i<salarySize-1; i++){
        total += salary[i];
    }
    
    return total/(salarySize-2);
}