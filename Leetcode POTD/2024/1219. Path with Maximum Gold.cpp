// Problem Link :- https://leetcode.com/problems/path-with-maximum-gold/

// Solved by Backtracking
// Time Complexity :- O(m * n * 4^g)    g = number of gold cells
// Space Complexity :- O(m * n + 4^g)

class Solution {
public:

    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

    bool isValid (int x, int y, int m, int n)
    {
        return (x >= 0 && y >= 0 && x < m && y < n);
    }

    int solve (int x, int y, int m, int n, vector<vector<bool>> &vis, vector<vector<int>>& grid)
    {
        vis[x][y] = true;

        int ans = grid[x][y];

        if (ans)
        {
            for (int i = 0; i < 4; i++)
            {
                int newx = x + dx[i], newy = y + dy[i];

                if (isValid(newx, newy, m, n) && grid[newx][newy] && !vis[newx][newy])
                {
                    int res = solve (newx, newy, m, n, vis, grid);
                    ans = max(ans, grid[x][y] + res);
                }
            }
        }

        vis[x][y] = false;

        return ans;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();

        int ans = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    vector<vector<bool>> vis(m, vector<bool> (n, false));

                    int res = solve (i, j, m, n, vis, grid);
                    ans = max(res, ans);
                }
            }
        }

        return ans;
    }
};



// Solved by Backtracking (Modifying the input grid)
// Time Complexity :- O(m * n * 4^g)    g = number of gold cells
// Space Complexity :- O(1)

class Solution {
public:

    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

    bool isValid (int x, int y, int m, int n)
    {
        return (x >= 0 && y >= 0 && x < m && y < n);
    }

    int solve (int x, int y, int m, int n, vector<vector<int>>& grid)
    {
        int val = grid[x][y], ans = val;
        grid[x][y] = 0;

        for (int i = 0; i < 4; i++)
        {
            int newx = x + dx[i], newy = y + dy[i];

            if (isValid(newx, newy, m, n) && grid[newx][newy])
            {
                int res = solve (newx, newy, m, n, grid);
                ans = max(ans, val + res);
            }
        }

        grid[x][y] = val;

        return ans;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();

        int ans = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    int res = solve (i, j, m, n, grid);
                    ans = max(res, ans);
                }
            }
        }

        return ans;
    }
};