//Problem Link :- https://leetcode.com/problems/number-of-islands/
//This is solved by DFS by me.
//Refer this to see BFS approach :- https://leetcode.com/problems/number-of-islands/discuss/2497913/Striver's-solution-or-AC-or-BFS-or-Visited-matrix-or-4-directions
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