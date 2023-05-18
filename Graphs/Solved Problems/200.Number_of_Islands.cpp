//Problem Link :- https://leetcode.com/problems/number-of-islands/

// Time Complexity :- O(m*n)
// Space Complexity :- O(m*n)

// Solved using DFS

class Solution {
public:
    
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, -1, 1};

    void DFS (int x, int y, int m, int n, vector<vector<bool>> &vis, vector<vector<char>>& grid)
    {
        vis[x][y] = true;

        for (int i = 0; i < 4; i++)
        {
            int newx = x + dx[i];
            int newy = y + dy[i];

            if (newx >= 0 && newx < m && newy >= 0 && newy < n && grid[newx][newy] == '1' && !vis[newx][newy])
                DFS (newx, newy, m, n, vis, grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis (m, vector<bool> (n, false));
        int count = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1' && !vis[i][j])
                {
                    DFS (i, j, m, n, vis, grid);
                    count++;
                }
            }
        }

        return count;
    }
};

class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    void DFS (vector<vector<char>>& grid, int x, int y, int row, int col)
    {
        if (x >= 0 && x < row && y >= 0 && y < col && grid[x][y] == '1')
        {
            grid[x][y] = '0';
            
            for (int i = 0; i<4; i++)
                DFS(grid, x + dx[i], y + dy[i], row, col);
        }
        
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;
        
        for (int i = 0; i<row; i++)
        {
            for (int j = 0; j<col; j++)
            {
                if (grid[i][j] == '1')
                {
                    DFS(grid, i, j, row, col);
                    ans++;
                }
            }
        }
       
        return ans;
    }
};



// Solved using BFS

class Solution {
public:

    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

    void BFS (int i, int j, int m, int n, vector<vector<bool>> &vis,  vector<vector<char>>& grid)
    {
        queue <pair<int, int>> q;
        q.emplace(i, j);
        vis[i][j] = true;

        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int newx = x + dx[i];
                int newy = y + dy[i];

                if (newx >= 0 && newx < m && newy >= 0 && newy < n && grid[newx][newy] == '1' && !vis[newx][newy])
                {
                    q.emplace(newx, newy);
                    vis[newx][newy] = true;
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis (m, vector<bool> (n, false));
        int count = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1' && !vis[i][j])
                {
                    BFS (i, j, m, n, vis, grid);
                    count++;
                }
            }
        }

        return count;
    }
};


// Solved using Union Find

class DSU {

public:
    
    vector<int> parent, rank, size;

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
};

class Solution {
public:

    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        DSU dsu(m*n - 1);
        int count = 0;

        vector<vector<int>> edges;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    int id = i * n + j;

                    if (i + 1 < m && grid[i + 1][j] == '1')
                        edges.push_back({id, (i + 1) * n + j});

                    if (j + 1 < n && grid[i][j + 1] == '1')
                        edges.push_back({id, i * n + j + 1});
                }
            }
        }

        for (auto &it : edges)
            dsu.UnionRank(it[0], it[1]);

        for (int cell = 0; cell < m * n; cell++)
        {
            if (grid[cell/n][cell % n] == '1' && dsu.parent[cell] == cell)
                count++;
        }

        return count;
    }
};