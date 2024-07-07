// Problem Link :- https://leetcode.com/problems/water-bottles/

// Solved by Simulation
// Time Complexity :- O(numBottles)
// Space Complexity :- O(1)

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
        int consumedBottles = 0;

        while (numBottles >= numExchange) 
        {
            consumedBottles += numExchange;
            numBottles -= numExchange;
            numBottles++;
        }

        return consumedBottles + numBottles;
    }
};



// Solved by Math
// Time Complexity :- O(log(numBottles))
// Space Complexity :- O(1)

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
        int water = numBottles;

        while (numBottles >= numExchange)
        {
            int extra = numBottles / numExchange;
            water += extra;
            numBottles = extra + numBottles % numExchange;
        }

        return water;
    }
};



// Most Optimal Solution
// Time Complexity :- O(1)
// Space Complexity :- O(1)

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
        int water = numBottles + (numBottles - 1)/(numExchange - 1);
        return water;
    }
};