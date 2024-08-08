// Problem Link :- https://leetcode.com/problems/spiral-matrix-iii/

// Solved by Simulation
// Time Complexity :- O(max(rows, cols)^2)
// Space Complexity :- O(rows * cols)

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {

        vector<vector<int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> traversed;

        for (int step = 1, direction = 0; traversed.size() < rows * cols; ) 
        {
            for (int i = 0; i < 2; ++i) 
            {
                for (int j = 0; j < step; ++j) 
                {
                    if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols)
                        traversed.push_back({rStart, cStart});
                    
                    rStart += dir[direction][0];
                    cStart += dir[direction][1];
                }

                direction = (direction + 1) % 4;
            }
            
            step++;
        }
        
        return traversed;
    }
};