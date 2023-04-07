// Problem Link :- https://leetcode.com/problems/number-of-enclaves/

// Time Complexity :- O(m*n)
// Space Complexity :- O(m*n)

// Solved by DFS

class Solution {
public:
    
    int m, n;
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

    void DFS (int x, int y, vector<vector<bool>> &vis, vector<vector<int>>& grid)
    {
        vis[x][y] = true;

        for (int dir = 0; dir < 4; dir++)
        {
            int newx = x + dx[dir];
            int newy = y + dy[dir];

            if (newx >= 0 && newx < m && newy >= 0 && newy < n && grid[newx][newy] == 1 && !vis[newx][newy])
                DFS (newx, newy, vis, grid);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        
        m = grid.size();
        n = grid[0].size();
        
        vector<vector<bool>> vis(m, vector<bool> (n, false));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i * j == 0 || i == m - 1 || j == n - 1) && grid[i][j] == 1 && !vis[i][j])
                    DFS (i, j, vis, grid);
            }
        }

        int count = 0;

        for (int i = 1; i < m - 1; i++)
        {
            for (int j = 1; j < n - 1; j++)
            {
                if (grid[i][j] == 1 && !vis[i][j])
                    count++;
            }
        }

        return count;
    }
};


// Solved by BFS

class Solution {
public:
    
    int m, n;
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

    void BFS (int i, int j, vector<vector<bool>> &vis, vector<vector<int>>& grid)
    {
        queue<pair<int, int>> q;
        q.emplace(i, j);
        vis[i][j] = true;

        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int dir = 0; dir < 4; dir++)
            {
                int newx = x + dx[dir];
                int newy = y + dy[dir];

                if (newx >= 0 && newx < m && newy >= 0 && newy < n && grid[newx][newy] == 1 && !vis[newx][newy])
                {
                    q.emplace(newx, newy);
                    vis[newx][newy] = true;
                }
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        
        m = grid.size();
        n = grid[0].size();
        
        vector<vector<bool>> vis(m, vector<bool> (n, false));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i * j == 0 || i == m - 1 || j == n - 1) && grid[i][j] == 1 && !vis[i][j])
                    BFS (i, j, vis, grid);
            }
        }

        int count = 0;

        for (int i = 1; i < m - 1; i++)
        {
            for (int j = 1; j < n - 1; j++)
            {
                if (grid[i][j] == 1 && !vis[i][j])
                    count++;
            }
        }

        return count;
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
    
    int numEnclaves(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

        DSU dsu (m * n);

        int boundary = m * n;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i * j == 0 || i == m - 1 || j == n - 1) && grid[i][j] == 1)
                    dsu.UnionRank(i * n + j, boundary);
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int newx = i + dx[dir];
                        int newy = j + dy[dir];

                        if (newx >= 0 && newx < m && newy >= 0 && newy < n && grid[newx][newy] == 1)
                            dsu.UnionRank(i * n + j, newx * n + newy);
                    }
                }
            }
        }

        int count = 0;

        for (int i = 1; i < m - 1; i++)
        {
            for (int j = 1; j < n - 1; j++)
            {
                if (grid[i][j] == 1 && dsu.findPar(i * n + j) != dsu.findPar(boundary))
                    count++;
            }
        }

        return count;
    }
};