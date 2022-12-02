//Problem Link :- https://leetcode.com/problems/number-of-enclaves/


//Solved by DFS

class Solution {
public:
    
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    void DFS (int i, int j, int m, int n, vector<vector<int>>& grid, vector <vector<int>> &vis)
    {
        vis[i][j] = 1;

        for (int it = 0; it < 4; it++)
        {
            int newx = i + dx[it];
            int newy = j + dy[it];

            if (newx >= 0 && newy >= 0 && newx < m && newy < n && !vis[newx][newy] && grid[newx][newy] == 1)
                DFS (newx, newy, m, n, grid, vis);
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector <vector <int>> vis (m, vector <int> (n, 0));
        
        for (int i = 0; i <  m; i++)
        {
            if (grid[i][0] == 1 && !vis[i][0])
                DFS (i, 0, m, n, grid, vis);
            
            if (grid[i][n - 1] == 1 && !vis[i][n - 1])
                DFS (i, n - 1, m, n, grid, vis);
        }
        
        for (int j = 0; j <  n; j++)
        {
            if (grid[0][j] == 1 && !vis[0][j])
                DFS (0, j, m, n, grid, vis);
            
            if (grid[m - 1][j] == 1 && !vis[m - 1][j])
                DFS (m - 1, j, m, n, grid, vis);
        }
        
        int ans = 0;
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!vis[i][j] && grid[i][j] == 1)
                    ans++;
            }
        }
        
        return ans;
    }
};


//Solved by BFS

class Solution {
public:
    
    int numEnclaves(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        vector <vector <int>> vis (m, vector <int> (n, 0));
        
        queue <pair <int, int>> q;
        
        for (int i = 0; i <  m; i++)
        {
            if (grid[i][0] == 1 && !vis[i][0])
            {
                vis[i][0] = 1;
                q.emplace(i, 0);
            }
            
            if (grid[i][n - 1] == 1 && !vis[i][n - 1])
            {
                vis[i][n - 1] = 1;
                q.emplace(i, n - 1);
            }
        }
        
        for (int j = 0; j <  n; j++)
        {
            if (grid[0][j] == 1 && !vis[0][j])
            {
                vis[0][j] = 1;
                q.emplace(0, j);
            }
            
            if (grid[m - 1][j] == 1 && !vis[m - 1][j])
            {
                vis[m - 1][j] = 1;
                q.emplace(m - 1, j);
            }
        }
        
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for (int it = 0; it < 4; it++)
            {
                int newx = x + dx[it];
                int newy = y + dy[it];

                if (newx >= 0 && newy >= 0 && newx < m && newy < n && !vis[newx][newy] && grid[newx][newy] == 1)
                {
                    vis[newx][newy] = 1;
                    q.emplace(newx, newy);
                }
            }
        }
        
        
        int ans = 0;
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!vis[i][j] && grid[i][j] == 1)
                    ans++;
            }
        }
        
        return ans;
    }
};