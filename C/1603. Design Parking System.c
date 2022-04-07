


typedef struct {
    int space[3];
} ParkingSystem;


ParkingSystem* parkingSystemCreate(int big, int medium, int small) {
    ParkingSystem* new = malloc(sizeof(ParkingSystem));
    new->space[0] = big;
    new->space[1] = medium;
    new->space[2] = small;
    
    return new;
}

bool parkingSystemAddCar(ParkingSystem* obj, int carType) {
    if(!obj->space[carType-1])
        return false;
        
    obj->space[carType-1]--;
    return true;
}

void parkingSystemFree(ParkingSystem* obj) {
    free(obj);
}

/**
 * Your ParkingSystem struct will be instantiated and called as such:
 * ParkingSystem* obj = parkingSystemCreate(big, medium, small);
 * bool param_1 = parkingSystemAddCar(obj, carType);
 
 * parkingSystemFree(obj);
*/