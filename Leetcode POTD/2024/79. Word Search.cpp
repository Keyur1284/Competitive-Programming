// Problem Link :- https://leetcode.com/problems/word-search/

// Solved by Backtracking
// Time Complexity :- O(m * n * 4^l)    m = number of rows, n = number of columns
// Space Complexity :- O(m * n)         l = length of the word

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int m = board.size(), n = board[0].size(), len = word.length();
        vector<vector<bool>> vis(m, vector<bool> (n, false));
        int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

        auto isValid = [&](int x, int y)
        {
            return (x >= 0 && x < m && y >= 0 && y < n);
        };

        function<bool(int, int, int)> DFS = [&](int index, int x, int y) -> bool
        {
            if (index == len)
                return true;

            if (!isValid(x, y) || vis[x][y] || board[x][y] != word[index])
                return false;

            vis[x][y] = true;
            bool ans = false;

            for (int k = 0; k < 4; k++)
            {
                int newx = x + dx[k], newy = y + dy[k];
                ans |= DFS(index + 1, newx, newy);
            }

            vis[x][y] = false;
            return ans;
        };

        for (int x = 0; x < m; x++)
        {
            for (int y = 0; y < n; y++)
            {
                if (DFS(0, x, y))
                    return true;
            }
        }

        return false;
    }
};