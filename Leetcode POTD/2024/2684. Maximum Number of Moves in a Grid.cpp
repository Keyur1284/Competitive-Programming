// Problem Link :- https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/

// Solved by Memoization Method
// Time Complexity :- O(m * n)
// Space Complexity :- O(m * n)

class Solution {
public:

    const int dirs[3] = {-1, 0, 1};

    bool isValid(int row, int col, int m, int n) 
    {
        return row >= 0 && col >= 0 && row < m && col < n;
    }

    int findMaxMoves(int row, int col, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp) {

        if (dp[row][col] != -1)
            return dp[row][col];

        int maxMoves = 0;

        for (int dir : dirs) 
        {
            int newRow = row + dir, newCol = col + 1;

            if (isValid(newRow, newCol, m, n) && grid[row][col] < grid[newRow][newCol]) 
            {
                maxMoves = max(maxMoves, 1 + findMaxMoves(newRow, newCol, m, n, grid, dp));
            }
        }

        return dp[row][col] = maxMoves;
    }

    int maxMoves(vector<vector<int>>& grid) {
        
        int maxMoves = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) 
        {
            int movesRequired = findMaxMoves(i, 0, m, n, grid, dp);
            maxMoves = max(maxMoves, movesRequired);
        }

        return maxMoves;
    }
};



// Solved by Tabulation Method
// Time Complexity :- O(m * n)
// Space Complexity :- O(m * n)

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        
        int maxMoves = 0;
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++)
            dp[i][0] = 1;

        for (int j = 1; j < n; j++) 
        {
            for (int i = 0; i < m; i++) 
            {
                if (grid[i][j] > grid[i][j - 1] && dp[i][j - 1])
                    dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1);
                
                if (i - 1 >= 0 && grid[i][j] > grid[i - 1][j - 1] && dp[i - 1][j - 1])
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                
                if (i + 1 < m && grid[i][j] > grid[i + 1][j - 1] && dp[i + 1][j - 1])
                    dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + 1);

                maxMoves = max(maxMoves, dp[i][j] - 1);
            }
        }

        return maxMoves;
    }
};



// Solved by Tabulation Method (Space Optimized)
// Time Complexity :- O(m * n)
// Space Complexity :- O(m)

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        
        int maxMoves = 0;
        int m = grid.size(), n = grid[0].size();

        vector<int> dp(m, 0);
        
        for (int i = 0; i < m; i++)
            dp[i] = 1;

        for (int j = 1; j < n; j++) 
        {
            vector<int> temp(m, 0);
            
            for (int i = 0; i < m; i++) 
            {
                if (grid[i][j] > grid[i][j - 1] && dp[i])
                    temp[i] = max(temp[i], dp[i] + 1);
                
                if (i - 1 >= 0 && grid[i][j] > grid[i - 1][j - 1] && dp[i - 1])
                    temp[i] = max(temp[i], dp[i - 1] + 1);
                
                if (i + 1 < m && grid[i][j] > grid[i + 1][j - 1] && dp[i + 1])
                    temp[i] = max(temp[i], dp[i + 1] + 1);

                maxMoves = max(maxMoves, temp[i] - 1);
            }

            dp = temp;
        }

        return maxMoves;
    }
};



// Solved by BFS
// Time Complexity :- O(n * m)
// Space Complexity :- O(n * m)

class Solution {
public:
    const int dirs[3] = {-1, 0, 1};

    bool isValid(int row, int col, int m, int n, vector<vector<bool>>& vis) 
    {
        return row >= 0 && col >= 0 && row < m && col < n && !vis[row][col];
    }

    int maxMoves(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();

        queue<vector<int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) 
        {
            vis[i][0] = true;
            q.push({i, 0, 0});
        }

        int maxMoves = 0;
        
        while (!q.empty()) 
        {
            int sz = q.size();

            while (sz--) 
            {
                vector<int> v = q.front();
                q.pop();

                int row = v[0], col = v[1], count = v[2];
                maxMoves = max(maxMoves, count);

                for (int dir : dirs) 
                {
                    int newRow = row + dir, newCol = col + 1;
                    
                    if (isValid(newRow, newCol, m, n, vis) && grid[row][col] < grid[newRow][newCol]) 
                    {
                        vis[newRow][newCol] = true;
                        q.push({newRow, newCol, count + 1});
                    }
                }
            }
        }

        return maxMoves;
    }
};