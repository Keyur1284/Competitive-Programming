// Problem Link :- https://leetcode.com/problems/design-parking-system/

// Time Complexity :- O(1)
// Space Complexity :- O(1)

class ParkingSystem {
public:
    
    unordered_map<int, int> space;

    ParkingSystem(int big, int medium, int small) {
        
        space[1] = big;
        space[2] = medium;
        space[3] = small;
    }
    
    bool addCar(int carType) {
        
        return (--space[carType] >= 0);
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */