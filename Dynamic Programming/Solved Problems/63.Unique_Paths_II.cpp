//Problem Link :- https://leetcode.com/problems/unique-paths-ii/

//Solved by Memoization Method
class Solution {
public:
    int func (int x, int y, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp)
    {
        if (x >= 0 && y >= 0 && obstacleGrid[x][y] == 1)
            return 0;
        
        if (x == 0 && y == 0)
            return 1;
        
        if (x < 0 || y < 0)
            return 0;
        
        if (dp[x][y] != -1)
            return dp[x][y];
        
        int up = func (x - 1, y, obstacleGrid, dp);
        int left = func (x, y - 1, obstacleGrid, dp);
        
        return dp[x][y] = up + left;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        
        vector <vector<int>> dp (row, vector<int> (col, -1));
        
        return func (row - 1, col - 1, obstacleGrid, dp);
    }
};


//Solved by Tabulation Method
class Solution {
public:
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        
        vector <vector<int>> dp (row, vector<int> (col, -1));
        
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    dp[i][j] = 0;
                    continue;
                }
                
                if (i == 0 && j == 0)
                {
                    dp[i][j] = 1;
                    continue;
                }
                
                int up = 0, left = 0;
                
                if (i > 0)
                    up = dp[i-1][j];
                
                if (j > 0)
                    left = dp[i][j-1];
                
                dp[i][j] = up + left;
            }
        }
        
        return dp[row - 1][col - 1];
    }
};


//Solved by Tabulation Method (Space Optimized)
class Solution {
public:
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        
        vector<int> dp (col, 0);
        
        for (int i = 0; i < row; i++)
        {
            vector <int> temp (col, 0);
            for (int j = 0; j < col; j++)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    temp[j] = 0;
                    continue;
                }
                
                if (i == 0 && j == 0)
                {
                    temp[j] = 1;
                    continue;
                }
                
                int up = 0, left = 0;
                
                if (i > 0)
                    up = dp[j];
                
                if (j > 0)
                    left = temp[j-1];
                
                temp[j] = up + left;
            }
            
            dp = temp;
        }
        
        return dp[col - 1];
    }
};