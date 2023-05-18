//Problem Link :- https://leetcode.com/problems/number-of-enclaves/


//Solved by DFS

class Solution {
public:

    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

    void DFS (int x, int y, int m , int n, vector<vector<bool>> &vis, vector<vector<int>>& grid)
    {
        vis[x][y] = true;

        for (int i = 0; i < 4; i++)
        {
            int newx = x + dx[i];
            int newy = y + dy[i];

            if (newx >= 0 && newx < m && newy >= 0 && newy < n && grid[newx][newy] && !vis[newx][newy])
                DFS (newx, newy, m, n, vis, grid);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis (m, vector<bool> (n, false));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i * j == 0 || i == m - 1 || j == n - 1) && grid[i][j] && !vis[i][j])
                    DFS (i, j, m, n, vis, grid);
            }
        }

        int enclaves = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] && !vis[i][j])
                    enclaves++;
            }
        }

        return enclaves;
    }
};


//Solved by BFS

class Solution {
public:
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

    int numEnclaves(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
    
        vector<vector<bool>> vis (m, vector <bool> (n, false));
        queue<pair<int, int>> q;
        
        for (int i = 0; i <  m; i++)
        {
            for (int j = 0; j <  n; j++)
            {
                if ((i * j == 0 || i == m - 1 || j == n - 1) && grid[i][j])
                {
                    vis[i][j] = true;
                    q.emplace(i, j);
                }
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

                if (newx >= 0 && newy >= 0 && newx < m && newy < n && !vis[newx][newy] && grid[newx][newy])
                {
                    vis[newx][newy] = 1;
                    q.emplace(newx, newy);
                }
            }
        }
        
        int enclaves = 0;
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!vis[i][j] && grid[i][j])
                    enclaves++;
            }
        }
        
        return enclaves;
    }
};


//Solved by Union Find

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

    int findPar(int node)
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
            parent[u] = v;

        else if (rank[u] > rank[v])
            parent[v] = u;

        else if (rank[u] == rank[v])
        {
            rank[u]++;
            parent[v] = u;
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
            size[v] += size[u];
            parent[u] = v;
        }

        else if (size[u] >= size[v])
        {
            size[u] += size[v];
            parent[v] = u;
        }
    }
};


class Solution {
public:
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

    int numEnclaves(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        DSU dsu (m * n);
        int boundary = m * n;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i * j == 0 || i == m - 1 || j == n - 1) && grid[i][j])
                    dsu.UnionRank(i * n + j, boundary);
            }
        }

        for (int i = 1; i < m - 1; i++)
        {
            for (int j = 1; j < n - 1; j++)
            {
                if (grid[i][j] == 1)
                {
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int newx = i + dx[dir];
                        int newy = j + dy[dir];

                        if (newx >= 0 && newx < m && newy >= 0 && newy < n && grid[newx][newy])
                            dsu.UnionRank(i * n + j, newx * n + newy);
                    }
                }
            }
        }

        int enclaves = 0;

        for (int i = 1; i < m - 1; i++)
        {
            for (int j = 1; j < n - 1; j++)
            {
                if (grid[i][j] && dsu.findPar(i * n + j) != dsu.findPar(boundary))
                    enclaves++;
            }
        }

        return enclaves;
    }
};