//Problem Link :- https://leetcode.com/problems/surrounded-regions/

class Solution {
public:
    
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    void DFS (int i, int j, int m, int n, vector<vector<char>>& board, vector <vector<int>> &vis)
    {
        vis[i][j] = 1;

        for (int it = 0; it < 4; it++)
        {
            int newx = i + dx[it];
            int newy = j + dy[it];

            if (newx >= 0 && newy >= 0 && newx < m && newy < n && !vis[newx][newy] && board[newx][newy] == 'O')
                DFS (newx, newy, m, n, board, vis);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        
        int m = board.size();
        int n = board[0].size();
        
        vector< vector<int>> vis(m , vector <int> (n, 0));
        
        for (int i = 0; i <  m; i++)
        {
            if (board[i][0] == 'O' && !vis[i][0])
                DFS (i, 0, m, n, board, vis);
            
            if (board[i][n - 1] == 'O' && !vis[i][n - 1])
                DFS (i, n - 1, m, n, board, vis);
        }
        
        for (int j = 0; j <  n; j++)
        {
            if (board[0][j] == 'O' && !vis[0][j])
                DFS (0, j, m, n, board, vis);
            
            if (board[m - 1][j] == 'O' && !vis[m - 1][j])
                DFS (m - 1, j, m, n, board, vis);
        }
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!vis[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};