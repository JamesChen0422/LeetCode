
//positive pyramid

void pyramid(int layer){
    for(int i=1; i<=layer; i++){
        for(int j=0; j<(layer-i); j++)
            printf(" ");
        for(int k=0; k<(2*i-1); k++)
            printf("*");
        printf("\n");
    }
}

====================================

//negative pyramid

void pyramid(int layer){
    for(int i=1; i<=layer; i++){
        for(int j=0; j<(i-1); j++)
            printf(" ");
        for(int k=0; k<((layer-i)*2+1); k++)
            printf("*");
        printf("\n");
    }
}


