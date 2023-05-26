// Problem Link :- https://leetcode.com/problems/max-area-of-island/

// Solved by DFS
// Time Complexity :- O(N * M)
// Space Complexity :- O(N * M)

class Solution {
public:

    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

    void DFS (int x, int y, int m, int n, int &area, vector<vector<bool>> &vis, vector<vector<int>>& grid)
    {
        vis[x][y] = true;
        area++;

        for (int i = 0; i < 4; i++)
        {
            int newx = x + dx[i];
            int newy = y + dy[i];
            
            if (newx >= 0 && newx < m && newy >= 0 && newy < n && grid[newx][newy] && !vis[newx][newy])
                DFS (newx, newy, m, n, area, vis, grid);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis (m, vector<bool> (n, false));
        int maxArea = 0;
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] && !vis[i][j])
                {
                    int area = 0;
                    DFS (i, j, m, n, area, vis, grid);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};


// Solved by Union Find

class DSU {

private:
    
    vector<int> parent, rank, size;

public:

    DSU (int n)
    {
        for (int i = 0; i <= n; i++)
        {
            parent.emplace_back(i);
            rank.emplace_back(0);
            size.emplace_back(1);
        }
    }

    int findPar (int node)
    {
        if (node == parent[node])
            return node;

        return parent[node] = findPar(parent[node]);
    }

    void UnionRank (int u, int v)
    {
        u = findPar(u);
        v = findPar(v);

        if (u == v)
            return;

        if (rank[u] < rank[v])
        {
            parent[u] = v;
        }

        else if (rank[u] > rank[v])
        {
            parent[v] = u;
        }

        else if (rank[u] == rank[v])
        {
            parent[v] = u;
            rank[u]++;
        }
    }

    void UnionSize (int u, int v)
    {
        u = findPar(u);
        v = findPar(v);

        if (u == v)
            return;

        if (size[u] < size[v])
        {
            parent[u] = v;
            size[v] += size[u];
        }

        else if (rank[u] >= rank[v])
        {
            parent[v] = u;
            size[u] += size[v];
        }
    }  

    int getSize (int u)
    {
        return size[u];
    }  
};


class Solution {
public:

    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

    void DFS (int x, int y, int m, int n, int &area, vector<vector<bool>> &vis, vector<vector<int>>& grid)
    {
        vis[x][y] = true;
        area++;

        for (int i = 0; i < 4; i++)
        {
            int newx = x + dx[i];
            int newy = y + dy[i];
            
            if (newx >= 0 && newx < m && newy >= 0 && newy < n && grid[newx][newy] && !vis[newx][newy])
                DFS (newx, newy, m, n, area, vis, grid);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        DSU dsu (m * n - 1);

        vector<vector<bool>> vis (m, vector<bool> (n, false));
        bool one = false;
        
        for (int x = 0; x < m; x++)
        {
            for (int y = 0; y < n; y++)
            {
                if (grid[x][y] && !vis[x][y])
                {
                    one = true;
                    vis[x][y] = true;

                    for (int i = 0; i < 4; i++)
                    {
                        int newx = x + dx[i];
                        int newy = y + dy[i];
                        
                        if (newx >= 0 && newx < m && newy >= 0 && newy < n && grid[newx][newy] && !vis[newx][newy])
                        {
                            if (dsu.findPar(x * n + y) != dsu.findPar(newx * n + newy))
                                dsu.UnionSize(x * n + y, newx * n + newy);
                        }
                    }
                }
            }
        }

        if (!one)
            return 0;

        int maxArea = 0;

        for (int i = 0; i < m * n; i++)
            maxArea = max(maxArea, dsu.getSize(i));

        return maxArea;
    }
};