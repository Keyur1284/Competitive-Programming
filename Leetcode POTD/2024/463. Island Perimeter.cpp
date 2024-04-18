// Problem Link :- https://leetcode.com/problems/island-perimeter/

// Solved by DFS
// Time Complexity :- O(row * col)
// Space Complexity :- O(row * col)

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int row = grid.size(), col = grid[0].size();
        int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};

        function<int(int, int)> DFS = [&](int x, int y)
        {
            if (x < 0 || y < 0 || x >= row || y >= col)
                return 1;

            if (!grid[x][y])
                return 1;

            if (grid[x][y] == 2)
                return 0;

            grid[x][y] = 2;
            int perimeter = 0;

            for (int k = 0; k < 4; k++)
            {
                int newx = x + dx[k], newy = y + dy[k];
                perimeter += DFS(newx, newy);
            }

            return perimeter;
        };

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j])
                    return DFS(i, j);
            }
        }

        return 0;
    }
};



// Solved by BFS
// Time Complexity :- O(row * col)
// Space Complexity :- O(row * col)

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int row = grid.size(), col = grid[0].size();
        int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};

        int perimeter = 0;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (!grid[i][j])
                    continue;

                queue<pair<int, int>> q;
                q.emplace(i, j);
                grid[i][j] = 2;

                while (!q.empty())
                {
                    auto [x, y] = q.front();
                    q.pop();

                    for (int k = 0; k < 4; k++)
                    {
                        int newx = x + dx[k], newy = y + dy[k];

                        if (newx < 0 || newy < 0 || newx >= row || newy >= col || !grid[newx][newy])
                        {
                            perimeter++;
                            continue;
                        }

                        if (grid[newx][newy] == 2)
                            continue;

                        grid[newx][newy] = 2;
                        q.emplace(newx, newy);
                    }
                }

                return perimeter;
            }
        }

        return perimeter;
    }
};