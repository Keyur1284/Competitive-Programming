// Problem Link :- https://leetcode.com/problems/count-sub-islands/

// Solved by DFS
// Time Complexity :- O(n * m)
// Space Complexity :- O(n * m)

class Solution {
public:

    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, -1, 1};

    bool isValid (int x, int y, int m, int n)
    {
        return (x >= 0 && y >= 0 && x < m && y < n);
    }

    void DFS (int x, int y, bool &island, int m, int n, vector<vector<int>>& grid1, vector<vector<int>>& grid2)
    {
        grid2[x][y] = 0;

        for (int i = 0; i < 4; i++)
        {
            int newx = x + dx[i], newy = y + dy[i];

            if (isValid(newx, newy, m, n) && grid2[newx][newy])
            {
                if (grid1[newx][newy])
                    DFS (newx, newy, island, m, n, grid1, grid2);

                else
                    island = false;
            }
        }
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        int m = grid1.size(), n = grid1[0].size();
        int subIslands = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid2[i][j] && grid1[i][j])
                {
                    bool island = true;
                    DFS (i, j, island, m, n, grid1, grid2);

                    subIslands += (island);
                } 
            }
        }

        return subIslands;
    }
};