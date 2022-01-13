int cmp(const void *a, const void *b)
{
    int  x = (*(int **)a)[0][1];
    int  y = (*(int **)b)[0][1];
    if(x > y)
        return 1;
    else if(x < y)
        return -1;
    return 0;
}

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize){
    int i, arrCount, pos;
    
    if((points==NULL) || (pointsSize==0))
        return 0;
   
    qsort(points, pointsSize, sizeof(int*), cmp);
    
    pos = points[0][1];
    arrCount = 1;
    
    for(i=1;i<pointsSize;i++){
        if(points[i][0] > pos){
            arrCount++;
            pos = points[i][1];
        }
    }
    
    return arrCount;
}


=====================================================================


#define MIN(a, b)   (a < b ? a : b)