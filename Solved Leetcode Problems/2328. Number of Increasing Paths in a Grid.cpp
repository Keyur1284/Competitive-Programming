// Problem Link :- https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/

// Solved by Sorting + DP
// Time Complexity :- O(m * n * log(m * n))
// Space Complexity :- O(m * n)

class Solution {
public:

    struct Cell {

        int row, col;

        Cell (int x, int y)
        {
            this->row = x;
            this->col = y;
        }
    };

    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1}, MOD = 1e9 + 7;

    bool isValid (int &x, int &y, int &m, int &n)
    {
        return (x >= 0 && y >= 0 && x < m && y < n);
    }

    int countPaths(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp (m, vector<int> (n, 1));

        vector<Cell> cells;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cells.emplace_back(Cell(i, j));
            }
        }

        sort (cells.begin(), cells.end(), [&grid](Cell &c1, Cell &c2){

            return grid[c1.row][c1.col] < grid[c2.row][c2.col];
        });

        int paths = 0;

        for (auto &cell : cells)
        {
            int x = cell.row, y = cell.col;
            paths += dp[x][y];
            paths %= MOD;

            for (int i = 0; i < 4; i++)
            {
                int newx = x + dx[i];
                int newy = y + dy[i];

                if (isValid(newx, newy, m, n) && grid[newx][newy] > grid[x][y])
                {
                    dp[newx][newy] += dp[x][y];
                    dp[newx][newy] %= MOD;
                }
            }
        }

        return paths;
    }
};



// Solved by DFS + Memoization
// Time Complexity :- O(m * n)
// Space Complexity :- O(m * n)

class Solution {
public:

    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1}, MOD = 1e9 + 7;

    bool isValid (int &x, int &y, int &m, int &n)
    {
        return (x >= 0 && y >= 0 && x < m && y < n);
    }

    int DFS (int x, int y, int &m, int &n, vector<vector<int>>& dp, vector<vector<int>>& grid)
    {
        if (dp[x][y])
            return dp[x][y];

        int paths = 1;

        for (int i = 0; i < 4; i++)
        {
            int newx = x + dx[i];
            int newy = y + dy[i];

            if (isValid(newx, newy, m, n) && grid[newx][newy] > grid[x][y])
            {
                paths += DFS (newx, newy, m, n, dp, grid) % MOD;
                paths %= MOD;
            }
        }

        return dp[x][y] = paths;
    }

    int countPaths(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp (m, vector<int> (n, 0));
        int paths = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                paths += DFS (i, j, m, n, dp, grid) % MOD;
                paths %= MOD;
            }
        }

        return paths;
    }
};