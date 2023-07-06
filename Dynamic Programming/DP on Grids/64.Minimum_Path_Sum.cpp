//Problem Link :- https://leetcode.com/problems/minimum-path-sum/

//Solved by Memoization Method
class Solution {
public:
    int func (int x, int y, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        if (x == 0 && y == 0)
            return grid[0][0];
        
        if (x < 0 || y < 0)
            return 1e9;
        
        if (dp[x][y] != -1)
            return dp[x][y];
        
        int up = grid[x][y] + func (x - 1, y, grid, dp);
        int left = grid[x][y] + func (x, y - 1, grid, dp);
        
        return dp[x][y] = min (up, left);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector <vector<int>> dp (m, vector<int> (n, -1));
        
        return func (m - 1, n - 1, grid, dp);
    }
};


//Solved by Tabulation Method
class Solution {
public:
    
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector <vector<int>> dp (m, vector<int> (n));
        
        for (int i = 0; i<m; i++)
        {
            for (int j = 0; j<n; j++)
            {
                if (i == 0 && j == 0)
                {
                    dp[i][j] = grid[i][j];
                    continue;
                }
                
                int up = 1e9, left = 1e9;
                
                if (i > 0)
                    up = dp[i - 1][j];
                
                if (j > 0)
                    left = dp[i][j - 1];
                
                dp[i][j] = grid[i][j] + min (up, left);
            }
        }
        
        return dp[m - 1][n - 1];
    }
};


//Solved by Tabulation Method (Space Optimized)
class Solution {
public:
    
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp (n, 0);
        
        for (int i = 0; i<m; i++)
        {
            vector <int> temp(n, 0);
            
            for (int j = 0; j<n; j++)
            {
                if (i == 0 && j == 0)
                {
                    temp[j] = grid[i][j];
                    continue;
                }
                
                int up = 1e9, left = 1e9;
                
                if (i > 0)
                    up = dp[j];
                
                if (j > 0)
                    left = temp[j - 1];
                
                temp[j] = grid[i][j] + min (up, left);
            }
            
            dp = temp;
        }
        
        return dp[n - 1];
    }
};




// Solved by doing path sum in the grid

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        
        for (int i = 1; i < n; i++)
            grid[i][0] += grid[i - 1][0];
        
        for (int i = 1; i < m; i++)
            grid[0][i] += grid[0][i - 1];
        
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        
        return grid[n - 1][m - 1];
    }
};