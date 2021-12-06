#define MIN(a,b) (a < b) ? a : b

int minCostToMoveChips(int* position, int positionSize){
    int i, P=0, I=0;
    
    for(i=0; i < positionSize; i++)
        position[i] % 2 == 0 ? P++ : I++;  
    
    return MIN(P,I);
}


==========================================================================



#define MIN(a,b) a < b ? a : b

int minCostToMoveChips(int* position, int positionSize){
    int i, P=0, I=0;
    
    for(i=0; i < positionSize; i++)
        if(position[i] % 2 == 0) P++;  
    
    return MIN(P, positionSize-P);
}