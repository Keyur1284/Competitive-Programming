//Problem Link :- https://leetcode.com/problems/surrounded-regions/

// Solved using DFS
class Solution {
public:

    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};
    
    void DFS (int x, int y, int m, int n, vector<vector<bool>> &vis, vector<vector<char>> &board)
    {
        vis[x][y] = true;
        
        for (int i = 0; i < 4; i++)
        {
            int newx = x + dx[i];
            int newy = y + dy[i];
            
            if (newx >= 0 && newx < m && newy >= 0 && newy < n && board[newx][newy] == 'O' && !vis[newx][newy])
                DFS (newx, newy, m, n, vis, board);
        }
    }

    void solve(vector<vector<char>>& board) {
        
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> vis(m, vector<bool> (n, false));
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i * j == 0 || i == m - 1 || j == n - 1) && board[i][j] == 'O' && !vis[i][j])
                    DFS (i, j, m, n, vis, board);
            }
        }
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O' && !vis[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};


// Solved using Union Find

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
};

class Solution {
public:

    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};

    void solve(vector<vector<char>>& board) {
        
        int m = board.size();
        int n = board[0].size();

        DSU dsu(n * m);
        int boundary = m * n;
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i * j == 0 || i == m - 1 || j == n - 1) && board[i][j] == 'O')
                    dsu.UnionRank (i * n + j, boundary);
            }
        }
        
        for (int i = 1; i < m - 1; i++)
        {
            for (int j = 1; j < n - 1; j++)
            {
                if (board[i][j] == 'O')
                {
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int newx = i + dx[dir];
                        int newy = j + dy[dir];

                        if (board[newx][newy] == 'O')
                            dsu.UnionRank(i * n + j, newx * n + newy);
                    }
                }
            }
        }
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O' && dsu.findPar(i * n + j) != dsu.findPar(boundary))
                    board[i][j] = 'X';
            }
        }
    }
};