class ParkingSystem {
private:
    int parkingSlot[3] = {0};
    int curParking[3] = {0};
public:
    ParkingSystem(int big, int medium, int small) {
        parkingSlot[0] = big;
        parkingSlot[1] = medium;
        parkingSlot[2] = small;

        curParking[0] = 0;
        curParking[1] = 0;
        curParking[2] = 0;
    }
    
    bool addCar(int carType) {
        if(curParking[carType-1] == parkingSlot[carType-1])
            return false;

        curParking[carType-1]++;
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
 