//Problem Link :- https://leetcode.com/problems/n-queens/

//Normal Solution
class Solution {
public:
    
    bool isSafe (int row, int col, vector <string> &board, int n)
    {
        int dupRow = row;
        int dupCol = col;
        
        //check upper left diagonal
        while (row >= 0 && col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            
            row--, col--;
        }
        
        row = dupRow;
        col = dupCol;
        
        //check left side
        while (col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            
            col--;
        }
        
        row = dupRow;
        col = dupCol;
        
        //check lower left diagonal
        while (row < n && col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            
            row++, col--;
        }
        
        return true;
    }
    
    void solve (int col, vector <string> &board, vector<vector<string>> &ans, int n)
    {
        if (col == n)
        {
            ans.emplace_back(board);
            return;
        }
        
        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, board, n))
            {
                board[row][col] = 'Q';
                solve (col + 1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;
        string s(n, '.');
        vector <string> board(n);
        
        for (auto &it : board)
            it = s;
        
        solve(0, board, ans, n);
        return ans;
    }
};


//Optimized Solution
class Solution {
public:
    
    
    void solve (int col, vector <string> &board, vector<vector<string>> &ans, vector <int> &leftRow, vector <int> &upperLeftDiagonal, vector <int> &lowerLeftDiagonal, int n)
    {
        if (col == n)
        {
            ans.emplace_back(board);
            return;
        }
        
        for (int row = 0; row < n; row++)
        {
            if (leftRow[row] == 0 && upperLeftDiagonal[row + col] == 0 && lowerLeftDiagonal[n - 1 + col - row] == 0)
            {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                upperLeftDiagonal[row + col] = 1;
                lowerLeftDiagonal[n - 1 + col - row] = 1;
                solve (col + 1, board, ans, leftRow, upperLeftDiagonal, lowerLeftDiagonal, n);
                board[row][col] = '.';
                leftRow[row] = 0;
                upperLeftDiagonal[row + col] = 0;
                lowerLeftDiagonal[n - 1 + col - row] = 0;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;
        string s(n, '.');
        vector <string> board(n);
        vector <int> leftRow(n, 0), upperLeftDiagonal(2*n - 1, 0), lowerLeftDiagonal(2*n - 1, 0);
        
        for (auto &it : board)
            it = s;
        
        solve(0, board, ans, leftRow, upperLeftDiagonal, lowerLeftDiagonal, n);
        return ans;
    }
};