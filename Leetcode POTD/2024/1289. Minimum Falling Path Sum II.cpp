// Problem Link :- https://leetcode.com/problems/minimum-falling-path-sum-ii/

// Solved by Memoization Method
// Time Complexity :- O(n^3)
// Space Complexity :- O(n^2)

class Solution {
public:

    int solve(int x, int y, int &n, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (x == 0)
            return grid[x][y];

        if (dp[x][y] != -1)
            return dp[x][y];

        int minSum = 1e9;

        for (int col = 0; col < n; col++)
        {
            if (col != y)
            {
                int sum = solve(x - 1, col, n, grid, dp);
                minSum = min(sum, minSum);
            }
        }

        return dp[x][y] = grid[x][y] + minSum; 
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size(), minSum = 1e9;
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int col = 0; col < n; col++)
        {
            int sum = solve(n - 1, col, n, grid, dp);
            minSum = min(sum, minSum);
        }

        return minSum;
    }
};



class Solution {
public:

    int solve(int x, int y, int &n, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (x == n - 1)
            return grid[x][y];

        if (dp[x][y] != -1)
            return dp[x][y];

        int minSum = 1e9;

        for (int col = 0; col < n; col++)
        {
            if (col != y)
            {
                int sum = solve(x + 1, col, n, grid, dp);
                minSum = min(sum, minSum);
            }
        }

        return dp[x][y] = grid[x][y] + minSum; 
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size(), minSum = 1e9;
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int col = 0; col < n; col++)
        {
            int sum = solve(0, col, n, grid, dp);
            minSum = min(sum, minSum);
        }

        return minSum;
    }
};



// Solved by Tabulation Method
// Time Complexity :- O(n^3)
// Space Complexity :- O(n^2)

class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, 1e9));

        for (int i = 0; i < n; i++)
            dp[0][i] = grid[0][i];

        for (int row = 1; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                for (int nextCol = 0; nextCol < n; nextCol++)
                {
                    if (nextCol != col)
                        dp[row][col] = min(dp[row][col], grid[row][col] + dp[row - 1][nextCol]);
                }
            }
        }

        int minSum = 1e9;
        
        for (int i = 0; i < n; i++)
            minSum = min(minSum, dp[n - 1][i]);

        return minSum;
    }
};



class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, 1e9));

        for (int i = 0; i < n; i++)
            dp[n - 1][i] = grid[n - 1][i];

        for (int row = n - 2; row >= 0; row--)
        {
            for (int col = 0; col < n; col++)
            {
                for (int nextCol = 0; nextCol < n; nextCol++)
                {
                    if (nextCol != col)
                        dp[row][col] = min(dp[row][col], grid[row][col] + dp[row + 1][nextCol]);
                }
            }
        }

        int minSum = 1e9;
        
        for (int i = 0; i < n; i++)
            minSum = min(minSum, dp[0][i]);

        return minSum;
    }
};



// Solved by Tabulation Method (Space Optimized)
// Time Complexity :- O(n^3)
// Space Complexity :- O(n)

class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<int> dp(n, 1e9);

        for (int i = 0; i < n; i++)
            dp[i] = grid[0][i];

        for (int row = 1; row < n; row++)
        {
            vector<int> temp(n, 1e9);

            for (int col = 0; col < n; col++)
            {
                for (int nextCol = 0; nextCol < n; nextCol++)
                {
                    if (nextCol != col)
                        temp[col] = min(temp[col], grid[row][col] + dp[nextCol]);
                }
            }

            dp = temp;
        }

        int minSum = 1e9;
        
        for (int i = 0; i < n; i++)
            minSum = min(minSum, dp[i]);

        return minSum;
    }
};



class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<int> dp(n, 1e9);

        for (int i = 0; i < n; i++)
            dp[i] = grid[n - 1][i];

        for (int row = n - 2; row >= 0; row--)
        {
            vector<int> temp(n, 1e9);

            for (int col = 0; col < n; col++)
            {
                for (int nextCol = 0; nextCol < n; nextCol++)
                {
                    if (nextCol != col)
                        temp[col] = min(temp[col], grid[row][col] + dp[nextCol]);
                }
            }

            dp = temp;
        }

        int minSum = 1e9;
        
        for (int i = 0; i < n; i++)
            minSum = min(minSum, dp[i]);

        return minSum;
    }
};



// Solved by Tabulation Method (Time Optimized)
// Time Complexity :- O(n^2)
// Space Complexity :- O(n^2)

class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<vector<int>> dp = grid;

        int minCol1 = -1, minCol2 = -1;

        for (int col = 0; col < n; col++)
        {
            if (minCol1 == -1 || dp[0][col] < dp[0][minCol1])
            {
                minCol2 = minCol1;
                minCol1 = col;
            }

            else if (minCol2 == -1 || dp[0][col] < dp[0][minCol2])
                minCol2 = col;
        }

        for (int row = 1; row < n; row++)
        {
            int newMinCol1 = -1, newMinCol2 = -1;

            for (int col = 0; col < n; col++)
            {
                dp[row][col] += (col == minCol1) ? dp[row - 1][minCol2] : dp[row - 1][minCol1];

                if (newMinCol1 == -1 || dp[row][col] < dp[row][newMinCol1])
                {
                    newMinCol2 = newMinCol1;
                    newMinCol1 = col;
                }

                else if (newMinCol2 == -1 || dp[row][col] < dp[row][newMinCol2])
                    newMinCol2 = col;
            }

            minCol1 = newMinCol1;
            minCol2 = newMinCol2;
        }

        return dp[n - 1][minCol1];
    }
};



class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<vector<int>> dp = grid;

        int minCol1 = -1, minCol2 = -1;

        for (int col = 0; col < n; col++)
        {
            if (minCol1 == -1 || dp[n - 1][col] < dp[n - 1][minCol1])
            {
                minCol2 = minCol1;
                minCol1 = col;
            }

            else if (minCol2 == -1 || dp[n - 1][col] < dp[n - 1][minCol2])
                minCol2 = col;
        }

        for (int row = n - 2; row >= 0; row--)
        {
            int newMinCol1 = -1, newMinCol2 = -1;

            for (int col = 0; col < n; col++)
            {
                dp[row][col] += (col == minCol1) ? dp[row + 1][minCol2] : dp[row + 1][minCol1];

                if (newMinCol1 == -1 || dp[row][col] < dp[row][newMinCol1])
                {
                    newMinCol2 = newMinCol1;
                    newMinCol1 = col;
                }

                else if (newMinCol2 == -1 || dp[row][col] < dp[row][newMinCol2])
                    newMinCol2 = col;
            }

            minCol1 = newMinCol1;
            minCol2 = newMinCol2;
        }

        return dp[0][minCol1];
    }
};



// Solved by Tabulation Method (Time and Space Optimized)
// Time Complexity :- O(n^2)
// Space Complexity :- O(n)

class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<int> dp = grid[0];

        int minCol1 = -1, minCol2 = -1, minVal1 = 1e9, minVal2 = 1e9;

        for (int col = 0; col < n; col++)
        {
            if (minCol1 == -1 || dp[col] < dp[minCol1])
            {
                minCol2 = minCol1;
                minCol1 = col;
                minVal2 = minVal1;
                minVal1 = dp[col];
            }

            else if (minCol2 == -1 || dp[col] < dp[minCol2])
            {
                minCol2 = col;
                minVal2 = dp[col];
            }
        }

        for (int row = 1; row < n; row++)
        {
            int newMinCol1 = -1, newMinCol2 = -1, newMinVal1 = 1e9, newMinVal2 = 1e9;

            for (int col = 0; col < n; col++)
            {
                dp[col] = grid[row][col] + ((col == minCol1) ? minVal2 : minVal1);

                if (newMinCol1 == -1 || dp[col] < dp[newMinCol1])
                {
                    newMinCol2 = newMinCol1;
                    newMinCol1 = col;
                    newMinVal2 = newMinVal1;
                    newMinVal1 = dp[col];
                }

                else if (newMinCol2 == -1 || dp[col] < dp[newMinCol2])
                {
                    newMinCol2 = col;
                    newMinVal2 = dp[col];
                }
            }

            minCol1 = newMinCol1;
            minCol2 = newMinCol2;
            minVal1 = newMinVal1;
            minVal2 = newMinVal2;
        }

        // We can also return minVal1 instead of dp[minCol1]
        return dp[minCol1];
    }
};



class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<int> dp = grid[n - 1];

        int minCol1 = -1, minCol2 = -1, minVal1 = 1e9, minVal2 = 1e9;

        for (int col = 0; col < n; col++)
        {
            if (minCol1 == -1 || dp[col] < dp[minCol1])
            {
                minCol2 = minCol1;
                minCol1 = col;
                minVal2 = minVal1;
                minVal1 = dp[col];
            }

            else if (minCol2 == -1 || dp[col] < dp[minCol2])
            {
                minCol2 = col;
                minVal2 = dp[col];
            }
        }

        for (int row = n - 2; row >= 0; row--)
        {
            int newMinCol1 = -1, newMinCol2 = -1, newMinVal1 = 1e9, newMinVal2 = 1e9;

            for (int col = 0; col < n; col++)
            {
                dp[col] = grid[row][col] + ((col == minCol1) ? minVal2 : minVal1);

                if (newMinCol1 == -1 || dp[col] < dp[newMinCol1])
                {
                    newMinCol2 = newMinCol1;
                    newMinCol1 = col;
                    newMinVal2 = newMinVal1;
                    newMinVal1 = dp[col];
                }

                else if (newMinCol2 == -1 || dp[col] < dp[newMinCol2])
                {
                    newMinCol2 = col;
                    newMinVal2 = dp[col];
                }
            }

            minCol1 = newMinCol1;
            minCol2 = newMinCol2;
            minVal1 = newMinVal1;
            minVal2 = newMinVal2;
        }

        // We can also return minVal1 instead of dp[minCol1]
        return dp[minCol1];
    }
};



// Solved by Tabulation Method (Time and Space Optimized) (Most Optimal)
// Time Complexity :- O(n^2)
// Space Complexity :- O(1)

class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();

        int minCol1 = -1, minCol2 = -1, minVal1 = 1e9, minVal2 = 1e9;

        for (int col = 0; col < n; col++)
        {
            if (minCol1 == -1 || grid[0][col] < minVal1)
            {
                minCol2 = minCol1;
                minCol1 = col;
                minVal2 = minVal1;
                minVal1 = grid[0][col];
            }

            else if (minCol2 == -1 || grid[0][col] < minVal2)
            {
                minCol2 = col;
                minVal2 = grid[0][col];
            }
        }

        for (int row = 1; row < n; row++)
        {
            int newMinCol1 = -1, newMinCol2 = -1, newMinVal1 = 1e9, newMinVal2 = 1e9;

            for (int col = 0; col < n; col++)
            {
                int minVal = grid[row][col] + ((col == minCol1) ? minVal2 : minVal1);

                if (newMinCol1 == -1 || minVal < newMinVal1)
                {
                    newMinCol2 = newMinCol1;
                    newMinCol1 = col;
                    newMinVal2 = newMinVal1;
                    newMinVal1 = minVal;
                }

                else if (newMinCol2 == -1 || minVal < newMinVal2)
                {
                    newMinCol2 = col;
                    newMinVal2 = minVal;
                }
            }

            minCol1 = newMinCol1;
            minCol2 = newMinCol2;
            minVal1 = newMinVal1;
            minVal2 = newMinVal2;
        }

        return minVal1;
    }
};



class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();

        int minCol1 = -1, minCol2 = -1, minVal1 = 1e9, minVal2 = 1e9;

        for (int col = 0; col < n; col++)
        {
            if (minCol1 == -1 || grid[n - 1][col] < minVal1)
            {
                minCol2 = minCol1;
                minCol1 = col;
                minVal2 = minVal1;
                minVal1 = grid[n - 1][col];
            }

            else if (minCol2 == -1 || grid[n - 1][col] < minVal2)
            {
                minCol2 = col;
                minVal2 = grid[n - 1][col];
            }
        }

        for (int row = n - 2; row >= 0; row--)
        {
            int newMinCol1 = -1, newMinCol2 = -1, newMinVal1 = 1e9, newMinVal2 = 1e9;

            for (int col = 0; col < n; col++)
            {
                int minVal = grid[row][col] + ((col == minCol1) ? minVal2 : minVal1);

                if (newMinCol1 == -1 || minVal < newMinVal1)
                {
                    newMinCol2 = newMinCol1;
                    newMinCol1 = col;
                    newMinVal2 = newMinVal1;
                    newMinVal1 = minVal;
                }

                else if (newMinCol2 == -1 || minVal < newMinVal2)
                {
                    newMinCol2 = col;
                    newMinVal2 = minVal;
                }
            }

            minCol1 = newMinCol1;
            minCol2 = newMinCol2;
            minVal1 = newMinVal1;
            minVal2 = newMinVal2;
        }

        return minVal1;
    }
};