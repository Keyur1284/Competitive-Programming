// Problem Link :- https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/

// Solved by DFS
// Time Complexity :- O((m * n) ^ 2)
// Space Complexity :- O(m * n)

class Solution {
public:

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

    bool isValid (int x, int y, int m, int n)
    {
        return (x >= 0 && y >= 0 && x < m && y < n);
    }

    bool isDisconnected (int islands)
    {
        return (islands > 1 || islands == 0);
    }

    void DFS (int x, int y, int m, int n, vector<vector<bool>> &vis, vector<vector<int>> &grid)
    {
        vis[x][y] = true;

        for (int i = 0; i < 4; i++)
        {
            int newx = x + dx[i];
            int newy = y + dy[i];

            if (isValid(newx, newy, m, n) && grid[newx][newy] && !vis[newx][newy])
                DFS (newx, newy, m, n, vis, grid);
        }
    }

    int countIslands (vector<vector<int>>& grid, int &m, int &n)
    {
        vector<vector<bool>> vis (m, vector<bool> (n, false));
        int islands = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] && !vis[i][j])
                {
                    DFS (i,  j, m, n, vis, grid);
                    islands++;
                }
            }
        }

        return islands;
    }

    int minDays(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        int islands = countIslands(grid, m, n);

        if (isDisconnected(islands))
            return 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    grid[i][j] = 0;
                    
                    islands = countIslands(grid, m, n);
                    if (isDisconnected(islands))
                        return 1;

                    grid[i][j] = 1;
                }
            }
        }
        
        return 2;
    }
};



// Solved by Tarjan's Algorithm
// Time Complexity :- O(m * n)
// Space Complexity :- O(m * n)

class Solution {
public:

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

    bool isValid (int x, int y, int m, int n)
    {
        return (x >= 0 && y >= 0 && x < m && y < n);
    }

    bool isDisconnected (int islands)
    {
        return (islands > 1 || islands == 0);
    }

    void DFS (int x, int y, int m, int n, vector<vector<bool>> &vis, vector<vector<int>> &grid)
    {
        vis[x][y] = true;

        for (int i = 0; i < 4; i++)
        {
            int newx = x + dx[i];
            int newy = y + dy[i];

            if (isValid(newx, newy, m, n) && grid[newx][newy] && !vis[newx][newy])
                DFS (newx, newy, m, n, vis, grid);
        }
    }

    int countIslands (vector<vector<int>>& grid, int &m, int &n)
    {
        vector<vector<bool>> vis (m, vector<bool> (n, false));
        int islands = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] && !vis[i][j])
                {
                    DFS (i,  j, m, n, vis, grid);
                    islands++;
                }
            }
        }

        return islands;
    }

    bool tarjan (int x, int y, int parx, int pary, int &m, int &n, int &clock, vector<vector<bool>> &vis, vector<vector<int>> &time_ins, vector<vector<int>> &lowestTime, vector<vector<int>> &grid)
    {
        vis[x][y] = true;
        int child = 0;
        time_ins[x][y] = lowestTime[x][y] = clock++;

        for (int i = 0; i < 4; i++)
        {
            int newx = x + dx[i];
            int newy = y + dy[i];

            if (isValid(newx, newy, m, n) && grid[newx][newy])
            {
                if (!vis[newx][newy])
                {
                    child++;

                    if (tarjan(newx, newy, x, y, m, n, clock, vis, time_ins, lowestTime, grid))
                        return true;

                    lowestTime[x][y] = min(lowestTime[x][y], lowestTime[newx][newy]);

                    if (lowestTime[newx][newy] >= time_ins[x][y] && parx != -1 && pary != -1)
                        return true;
                }

                else
                    lowestTime[x][y] = min(lowestTime[x][y], time_ins[newx][newy]);
            }
        }

        if (parx == -1 && pary == -1 && child > 1)
            return true;

        return false;
    }

    int minDays(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        int islands = countIslands(grid, m, n);

        if (isDisconnected(islands))
            return 0;

        vector<vector<bool>> vis (m, vector<bool> (n, false));
        vector<vector<int>> time_ins (m, vector<int> (n)), lowestTime (m, vector<int> (n));
        int clock = 0, countOnes = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                countOnes += grid[i][j];

                if (grid[i][j] && !vis[i][j])
                {
                    if (tarjan (i, j, -1, -1, m, n, clock, vis, time_ins, lowestTime, grid))
                        return 1;
                }
            }
        }

        return (countOnes == 1) ? 1 : 2;
    }
};