

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n){
    int place = 0, empty = 0, index = 0;
    for(int i=0; i<flowerbedSize; i++){
        if(!flowerbed[i])
            empty++;
        else if(flowerbed[i]){            
            if(empty>=2){
                if(index)
                    place += (empty-1)/2;
                else
                    place += (empty/2);
                
            }
            index = i+1;
            empty=0;        
        }         
    }

    if(empty>=2)
        place += (empty+1)/2;

    if(flowerbedSize == 1 && empty)
        place = 1;

    if(n>place)
        return false;
    else 
        return true;
}