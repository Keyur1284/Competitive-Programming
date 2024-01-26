// Problem Link :- https://leetcode.com/problems/out-of-boundary-paths/

// Solved by Memoization Method
// Time Complexity :- O(m * n * maxMove)
// Space Complexity :- O(m * n * maxMove)

class Solution {
public:

    long MOD = 1e9 + 7;
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

    bool isOutOfBoundary (int x, int y, int m, int n)
    {
        return (x < 0 || y < 0 || x == m || y == n);
    }

    int countPaths (int x, int y, int maxMove, int &m, int &n, vector<vector<vector<int>>> &dp)
    {
        if (isOutOfBoundary(x, y, m, n))
            return 1;

        if (dp[x][y][maxMove] != -1)
            return dp[x][y][maxMove];

        long paths = 0;

        if (maxMove)
        {
            for (int i = 0; i < 4; i++)
            {
                int newx = x + dx[i], newy = y + dy[i];
                paths += countPaths(newx, newy, maxMove - 1, m, n, dp) % MOD;
                paths %= MOD;
            }
        }

        return dp[x][y][maxMove] = paths;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (maxMove + 1, -1)));
        return countPaths(startRow, startColumn, maxMove, m, n, dp);
    }   
};



// Solved by Tabulation Method
// Time Complexity :- O(m * n * maxMove)
// Space Complexity :- O(m * n * maxMove)

class Solution {
public:

    bool isOutOfBoundary (int x, int y, int m, int n)
    {
        return (x < 0 || y < 0 || x == m || y == n);
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        if (!maxMove)
            return 0;

        long MOD = 1e9 + 7;
        int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (maxMove + 1, 0)));

        for (int i = 0; i < m; i++)
            dp[i][0][1]++, dp[i][n - 1][1]++;

        for (int i = 0; i < n; i++)
            dp[0][i][1]++, dp[m - 1][i][1]++;

        for (int moves = 2; moves <= maxMove; moves++)
        {
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n ; j++)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        int newx = i + dx[k], newy = j + dy[k];
                        
                        if (isOutOfBoundary(newx, newy, m, n))
                            continue;
                        
                        dp[i][j][moves] += dp[newx][newy][moves - 1] % MOD;
                        dp[i][j][moves] %= MOD;
                    }
                }
            }
        }

        long paths = 0;

        for (int moves = 1; moves <= maxMove; moves++)
        {
            paths += dp[startRow][startColumn][moves] % MOD;
            paths %= MOD;
        }

        return paths;
    }   
};



// Solved by Tabulation Method (Space Optimized)
// Time Complexity :- O(m * n * maxMove)
// Space Complexity :- O(m * n)

class Solution {
public:

    bool isOutOfBoundary (int x, int y, int m, int n)
    {
        return (x < 0 || y < 0 || x == m || y == n);
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        if (!maxMove)
            return 0;

        long MOD = 1e9 + 7;
        int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

        vector<vector<int>> dp(m, vector<int> (n, 0));

        for (int i = 0; i < m; i++)
            dp[i][0]++, dp[i][n - 1]++;

        for (int i = 0; i < n; i++)
            dp[0][i]++, dp[m - 1][i]++;

        long paths = dp[startRow][startColumn];

        for (int moves = 2; moves <= maxMove; moves++)
        {
            vector<vector<int>> temp(m, vector<int> (n, 0));
            
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n ; j++)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        int newx = i + dx[k], newy = j + dy[k];
                        
                        if (isOutOfBoundary(newx, newy, m, n))
                            continue;
                        
                        temp[i][j] += dp[newx][newy] % MOD;
                        temp[i][j] %= MOD;
                    }
                }
            }

            dp = temp;
            paths += dp[startRow][startColumn] % MOD;
            paths %= MOD;
        }

        return paths;
    }   
};