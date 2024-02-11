// Problem Link :- https://leetcode.com/problems/cherry-pickup-ii/

// Solved by Memoization Method
// Time Complexity :- O(n * m * m)
// Space Complexity :- O(n * m * m)

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m, -1)));

        auto isValid = [&](int x, int y)
        {
            return (x >= 0 && x < n && y >= 0 && y < m);
        };

        function<int(int, int, int)> solve = [&](int x, int y1, int y2) -> int {

            if (x == n - 1)
            {
                return (y1 == y2) ? grid[x][y1] : grid[x][y1] + grid[x][y2];
            }

            if (dp[x][y1][y2] != -1)
                return dp[x][y1][y2];

            int maxCherries = 0, currCherries = (y1 == y2) ? grid[x][y1] : grid[x][y1] + grid[x][y2];

            for (int dy1 = -1; dy1 <= 1; dy1++)
            {
                for (int dy2 = -1; dy2 <= 1; dy2++)
                {
                    int newy1 = y1 + dy1, newy2 = y2 + dy2;
                    
                    if (isValid(x + 1, newy1) && isValid(x + 1, newy2))
                    {
                        int cherries = solve(x + 1, newy1, newy2);
                        maxCherries = max(maxCherries, cherries);
                    }
                }
            }

            return dp[x][y1][y2] = maxCherries + currCherries;
        };

        return solve(0, 0, m - 1);
    }
};



// Solved by Tabulation Method
// Time Complexity :- O(n * m * m)
// Space Complexity :- O(n * m * m)

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m, 0)));

        auto isValid = [&](int x, int y)
        {
            return (x >= 0 && x < n && y >= 0 && y < m);
        };

        for (int x = n - 1; x >= 0; x--)
        {
            for (int y1 = 0; y1 < m; y1++)
            {
                for (int y2 = 0; y2 < m; y2++)
                {
                    if (x == n - 1)
                    {
                        dp[x][y1][y2] = (y1 == y2) ? grid[x][y1] : grid[x][y1] + grid[x][y2];
                        continue;
                    }

                    int maxCherries = 0, currCherries = (y1 == y2) ? grid[x][y1] : grid[x][y1] + grid[x][y2];

                    for (int dy1 = -1; dy1 <= 1; dy1++)
                    {
                        for (int dy2 = -1; dy2 <= 1; dy2++)
                        {
                            int newy1 = y1 + dy1, newy2 = y2 + dy2;
                            
                            if (isValid(x + 1, newy1) && isValid(x + 1, newy2))
                            {
                                int cherries = dp[x + 1][newy1][newy2];
                                maxCherries = max(maxCherries, cherries);
                            }
                        }
                    }

                    dp[x][y1][y2] = maxCherries + currCherries;
                }
            }
        }

        return dp[0][0][m - 1];
    }
};



// Solved by Tabulation Method (Space Optimized)
// Time Complexity :- O(n * m * m)
// Space Complexity :- O(m * m)

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (m, 0));

        auto isValid = [&](int x, int y)
        {
            return (x >= 0 && x < n && y >= 0 && y < m);
        };

        for (int x = n - 1; x >= 0; x--)
        {
            vector<vector<int>> temp(m, vector<int> (m, 0));

            for (int y1 = 0; y1 < m; y1++)
            {
                for (int y2 = 0; y2 < m; y2++)
                {
                    if (x == n - 1)
                    {
                        temp[y1][y2] = (y1 == y2) ? grid[x][y1] : grid[x][y1] + grid[x][y2];
                        continue;
                    }

                    int maxCherries = 0, currCherries = (y1 == y2) ? grid[x][y1] : grid[x][y1] + grid[x][y2];

                    for (int dy1 = -1; dy1 <= 1; dy1++)
                    {
                        for (int dy2 = -1; dy2 <= 1; dy2++)
                        {
                            int newy1 = y1 + dy1, newy2 = y2 + dy2;
                            
                            if (isValid(x + 1, newy1) && isValid(x + 1, newy2))
                            {
                                int cherries = dp[newy1][newy2];
                                maxCherries = max(maxCherries, cherries);
                            }
                        }
                    }

                    temp[y1][y2] = maxCherries + currCherries;
                }
            }

            dp = temp;
        }

        return dp[0][m - 1];
    }
};