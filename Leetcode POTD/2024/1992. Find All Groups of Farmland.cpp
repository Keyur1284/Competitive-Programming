// Problem Link :- https://leetcode.com/problems/find-all-groups-of-farmland/

// Solved by DFS
// Time Complexity :- O(m * n)
// Space Complexity :- O(m * n)

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        
        int m = land.size(), n = land[0].size();
        int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, -1, 1};
        vector<vector<bool>> vis(m, vector<bool> (n, false));
        vector<vector<int>> farmLands;
        int maxEndX = 0, maxEndY = 0;

        auto isValid = [&](int x, int y)
        {
            return (x >= 0 && y >= 0 && x < m && y < n && land[x][y]);
        };

        function<void(int, int)> DFS = [&](int x, int y) -> void
        {
            vis[x][y] = true;

            for (int k = 0; k < 4; k++)
            {
                int newx = x + dx[k], newy = y + dy[k];

                if (isValid(newx, newy) && !vis[newx][newy])
                {
                    DFS(newx, newy);
                    maxEndX = max(maxEndX, newx);
                    maxEndY = max(maxEndY, newy);
                }
            }
        };
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!vis[i][j] && land[i][j])
                {
                    maxEndX = i;
                    maxEndY = j;
                    DFS(i, j);
                    vector<int> farmLand = {i, j, maxEndX, maxEndY};
                    farmLands.emplace_back(farmLand);
                }
            }
        }

        return farmLands;
    }
};



// Solved by BFS
// Time Complexity :- O(m * n)
// Space Complexity :- O(m * n)

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        
        int m = land.size(), n = land[0].size();
        int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, -1, 1};
        vector<vector<bool>> vis(m, vector<bool> (n, false));
        vector<vector<int>> farmLands;
        int maxEndX = 0, maxEndY = 0;

        auto isValid = [&](int x, int y)
        {
            return (x >= 0 && y >= 0 && x < m && y < n && land[x][y]);
        };

        function<void(int, int)> BFS = [&](int x, int y) -> void
        {
            queue<pair<int, int>> q;
            q.emplace(x, y);
            vis[x][y] = true;

            while (!q.empty())
            {
                auto [curx, cury] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++)
                {
                    int newx = curx + dx[k], newy = cury + dy[k];

                    if (isValid(newx, newy) && !vis[newx][newy])
                    {
                        q.emplace(newx, newy);
                        vis[newx][newy] = true;
                        maxEndX = max(maxEndX, newx);
                        maxEndY = max(maxEndY, newy);
                    }
                }
            }
        };

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!vis[i][j] && land[i][j])
                {
                    maxEndX = i;
                    maxEndY = j;
                    BFS(i, j);
                    vector<int> farmLand = {i, j, maxEndX, maxEndY};
                    farmLands.emplace_back(farmLand);
                }
            }
        }

        return farmLands;
    }
};



class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        
        int m = land.size(), n = land[0].size();
        int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, -1, 1};
        vector<vector<bool>> vis(m, vector<bool> (n, false));
        vector<vector<int>> farmLands;
        int maxEndX = 0, maxEndY = 0;

        auto isValid = [&](int x, int y)
        {
            return (x >= 0 && y >= 0 && x < m && y < n && land[x][y]);
        };

        function<pair<int, int>(int, int)> BFS = [&](int x, int y) -> pair<int, int>
        {
            queue<pair<int, int>> q;
            q.emplace(x, y);
            int lastX = x, lastY = y;
            vis[x][y] = true;

            while (!q.empty())
            {
                auto [curx, cury] = q.front();
                lastX = curx;
                lastY = cury;
                q.pop();

                for (int k = 0; k < 4; k++)
                {
                    int newx = curx + dx[k], newy = cury + dy[k];

                    if (isValid(newx, newy) && !vis[newx][newy])
                    {
                        q.emplace(newx, newy);
                        vis[newx][newy] = true;
                    }
                }
            }

            return {lastX, lastY};
        };

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!vis[i][j] && land[i][j])
                {
                    auto last = BFS(i, j);
                    vector<int> farmLand = {i, j, last.first, last.second};
                    farmLands.emplace_back(farmLand);
                }
            }
        }

        return farmLands;
    }
};



// Solved by Greedy Approach
// Time Complexity :- O(m * n)
// Space Complexity :- O(1)

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        
        int m = land.size(), n = land[0].size();
        vector<vector<int>> farmLands;
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (land[i][j])
                {
                    int endX, endY;
                    
                    for (endX = i; endX < m && land[endX][j]; endX++)
                    {
                        for (endY = j; endY < n && land[endX][endY]; endY++)
                            land[endX][endY] = 0;
                    }

                    farmLands.push_back({i, j, endX - 1, endY - 1});
                }
            }
        }

        return farmLands;
    }
};