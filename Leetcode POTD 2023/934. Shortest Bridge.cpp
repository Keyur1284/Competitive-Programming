// Problem Link :- https://leetcode.com/problems/shortest-bridge/

// Time Complexity :- O(n^2)
// Space Complexity :- O(n^2)

// Solved by DFS + BFS

class Solution {
public:

    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

    void DFS (int x, int y, int n, queue<pair<int, int>> &BFS, vector<vector<int>>& grid)
    {
        grid[x][y] = 2;
        BFS.emplace(x, y);

        for (int i = 0; i < 4; i++)
        {
            int newx = x + dx[i];
            int newy = y + dy[i];
            
            if (newx >= 0 && newx < n && newy >= 0 && newy < n && grid[newx][newy] == 1)
                DFS (newx, newy, n, BFS, grid);
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {

        int n = grid.size();
        int firstX = -1, firstY = -1;
        bool flag = false;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    firstX = i;
                    firstY = j;
                    flag = true;
                    break;
                }
            }

            if (flag)
                break;
        }
        
        queue<pair<int, int>> BFS;
        DFS (firstX, firstY, n, BFS, grid);

        int distance = 0;

        while (!BFS.empty())
        {
            int size = BFS.size();

            while (size--)
            {
                int x = BFS.front().first;
                int y = BFS.front().second;
                BFS.pop();
                
                for (int i = 0; i < 4; i++)
                {
                    int newx = x + dx[i];
                    int newy = y + dy[i];

                    if (newx >= 0 && newx < n && newy >= 0 && newy < n)
                    {
                        if (grid[newx][newy] == 1)
                            return distance;

                        else if (grid[newx][newy] == 0)
                        {
                            grid[newx][newy] = 2;
                            BFS.emplace(newx, newy);
                        }
                    }
                }
                
            }

            distance++;
        }

        return 0;
    }
};