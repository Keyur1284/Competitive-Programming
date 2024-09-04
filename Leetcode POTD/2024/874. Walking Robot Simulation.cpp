// Problem Link :- https://leetcode.com/problems/walking-robot-simulation/

// Solved by Simulation
// Time Complexity :- O(9 * m + n)  m = no. of commands
// Space Complexity :- O(n)         n = no. of obstacles

class Solution {
private:
    
    static const int HASH_MULTIPLIER = 60001;

    int hashCoordinates(int x, int y) 
    { 
        return x + HASH_MULTIPLIER * y; 
    }

public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        unordered_set<int> obstacleSet;

        for (auto &obstacle : obstacles) 
            obstacleSet.emplace(hashCoordinates(obstacle[0], obstacle[1]));

        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> currentPosition = {0, 0};
        int maxDistanceSquared = 0, currentDirection = 0;

        for (auto &command : commands) 
        {
            if (command == -1) 
                currentDirection = (currentDirection + 1) % 4;

            else if (command == -2)
                currentDirection = (currentDirection - 1 + 4) % 4;

            else
            {
                vector<int> direction = directions[currentDirection];
                
                for (int step = 0; step < command; step++) 
                {
                    int nextX = currentPosition[0] + direction[0], nextY = currentPosition[1] + direction[1];
                    
                    if (obstacleSet.count(hashCoordinates(nextX, nextY)))
                        break;
                    
                    currentPosition[0] = nextX;
                    currentPosition[1] = nextY;
                }

                int distanceSquared = currentPosition[0] * currentPosition[0] + currentPosition[1] * currentPosition[1];
                maxDistanceSquared = max(maxDistanceSquared, distanceSquared);
            }
        }

        return maxDistanceSquared;
    }
};