

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
    int start = 0, sum = 0, total = 0;

    for(int i = 0; i<gasSize; i++) {
        total += gas[i] - cost[i];

        sum += gas[i] - cost[i];
        if(sum < 0){
          sum = 0;
          start = i + 1;
        }
    }
  
    if(total < 0 ) return -1; 
    return start;  
}