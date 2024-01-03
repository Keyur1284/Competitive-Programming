// Problem Link :- https://leetcode.com/problems/shortest-path-in-binary-matrix/

// Solved using normal queue
// Time Complexity :- O(n^2)
// Space Complexity :- O(n^2)

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();

        if (grid[0][0] | grid[n - 1][n - 1])
            return -1;

        vector<vector<int>> dist (n, vector<int> (n, INT_MAX));
        queue<pair<int, int>> BFS;

        BFS.emplace(0, 0);
        dist[0][0] = 1;

        while (!BFS.empty())
        {
            auto it = BFS.front();
            int x = it.first;
            int y = it.second;
            BFS.pop();

            if (x == n - 1 && y == n - 1)
                return dist[x][y];

            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    int newx = x + i;
                    int newy = y + j;

                    if (newx >= 0 && newx < n && newy >= 0 && newy < n && !grid[newx][newy])
                    {
                        if (dist[x][y] + 1 < dist[newx][newy])
                        {
                            dist[newx][newy] = dist[x][y] + 1;
                            BFS.emplace(newx, newy);
                        }
                    }
                }
            }
        }

        return -1;
    }
};


// Solved by using priority_queue
// Time Complexity :- O(n^2 log n^2)
// Space Complexity :- O(n^2)

class Solution {
public:

    bool isValid (int &x, int &y, int &row, int &col)
    {
        return (x >= 0 && x < row && y >= 0 && y < col);
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();

        if (grid[0][0] | grid[n - 1][n - 1])
            return -1;

        vector<vector<int>> dist (n, vector<int> (n, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> BFS;

        BFS.push({1, {0, 0}});
        dist[0][0] = 1;

        while (!BFS.empty())
        {
            auto it = BFS.top();
            int steps = it.first;
            int x = it.second.first;
            int y = it.second.second;
            BFS.pop();

            if (x == n - 1 && y == n - 1)
                return steps;

            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    int newx = x + i;
                    int newy = y + j;

                    if (isValid(newx, newy, n, n) && !grid[newx][newy])
                    {
                        if (steps + 1 < dist[newx][newy])
                        {
                            dist[newx][newy] = steps + 1;
                            BFS.push({dist[newx][newy], {newx, newy}});
                        }
                    }
                }
            }
        }

        return -1;
    }
};