

int nearestValidPoint(int x, int y, int** points, int pointsSize, int* pointsColSize){
    int* dist = malloc(pointsSize * sizeof(int));
    memset(dist, -1, pointsSize*sizeof(int));
    
    for(int i=0; i<pointsSize; i++){
        if(points[i][0] == x)
            dist[i] = abs((points[i][1]-y));    
        if(points[i][1] == y)
            dist[i] = abs((points[i][0]-x));       
        
    }
    
    int min = INT_MAX, ans=-1;
    for(int i=0; i<pointsSize; i++){
        printf("%d \n", dist[i]);
        if(dist[i] > -1){
            if(min > dist[i]){
                min = dist[i];
                ans = i;
            }
        }
    }
    
    return ans;
}