// Problem Link :- https://leetcode.com/problems/largest-local-values-in-a-matrix/

// Solved by Simulation
// Time Complexity :- O(n^2)
// Space Complexity :- O(n^2)

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<vector<int>> maxLocal(n - 2, vector<int> (n - 2));

        for (int i = 0, x = 1; i < n - 2; i++, x++)
        {
            for (int j = 0, y = 1; j < n - 2; j++, y++)
            {
                int maxi = 0;

                for (int dx = -1; dx <= 1; dx++)
                {
                    for (int dy = -1; dy <= 1; dy++)
                    {
                        maxi = max(maxi, grid[x + dx][y + dy]);
                    }
                }

                maxLocal[i][j] = maxi;
            }
        }

        return maxLocal;
    }
};



class Solution {
public: 

    int findMax(int x, int y, vector<vector<int>>& grid) 
    {
        int maxElement = 0;
        
        for (int i = x; i < x + 3; i++) 
        {
            for (int j = y; j < y + 3; j++) 
            {
                maxElement = max(maxElement, grid[i][j]);
            }
        }
        
        return maxElement;
    }

    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<vector<int>> maxLocal(n - 2, vector<int>(n - 2, 0));
        
        for (int i = 0; i < n - 2; i++) 
        {
            for (int j = 0; j < n - 2; j++) 
            {
                maxLocal[i][j] = findMax(i, j, grid);
            }
        }
        
        return maxLocal;
    }
};