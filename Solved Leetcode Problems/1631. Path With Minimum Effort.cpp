// Problem Link :- https://leetcode.com/problems/path-with-minimum-effort/

// Solved by Dijkstra's Algorithm
// Time Complexity :- O(n * m * log(n * m))
// Space Complexity :- O(n * m)

class Solution {
public:

    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

    bool isValid (int x, int y, int n, int m)
    {
        return (x >= 0 && y >= 0 && x < n && y < m);
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> effort (n, vector<int> (m, 1e9));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> BFS;
        
        BFS.push({0, {0, 0}});
        effort[0][0] = 0;

        while (!BFS.empty())
        {
            auto it = BFS.top();
            int currEffort = it.first;
            int x = it.second.first;
            int y = it.second.second;
            BFS.pop();
            
            if (x == n - 1 && y == m - 1)
                return currEffort;

            for (int i = 0; i < 4; i++)
            {
                int newx = x + dx[i];
                int newy = y + dy[i];
                
                if (isValid(newx, newy, n, m))
                {
                    int newEffort = max(currEffort, abs(heights[newx][newy] - heights[x][y]));

                    if (newEffort < effort[newx][newy])
                    {
                        effort[newx][newy] = newEffort;
                        BFS.push({newEffort, {newx, newy}});
                    }
                }
            }
        }

        return 0;
    }
};



// Solved by BFS
// Time Complexity :- O(n * m)
// Space Complexity :- O(n * m)

class Solution {
public:

    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

    bool isValid (int x, int y, int n, int m)
    {
        return (x >= 0 && y >= 0 && x < n && y < m);
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> effort (n, vector<int> (m, 1e9));
        queue<pair<int, int>> BFS;
        
        BFS.emplace(0, 0);
        effort[0][0] = 0;

        while (!BFS.empty())
        {
            auto it = BFS.front();
            int x = it.first;
            int y = it.second;
            BFS.pop();

            for (int i = 0; i < 4; i++)
            {
                int newx = x + dx[i];
                int newy = y + dy[i];
                
                if (isValid(newx, newy, n, m))
                {
                    int newEffort = max(effort[x][y], abs(heights[newx][newy] - heights[x][y]));

                    if (newEffort < effort[newx][newy])
                    {
                        effort[newx][newy] = newEffort;
                        BFS.emplace(newx, newy);
                    }
                }
            }
        }

        return effort[n - 1][m - 1];
    }
};



// Solved by Binary Search + DFS
// Time Complexity :- O(n * m * log(n * m))
// Space Complexity :- O(n * m)

class Solution {
public:

    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

    bool isValid (int x, int y, int n, int m)
    {
        return (x >= 0 && y >= 0 && x < n && y < m);
    }

    bool DFS (vector<vector<int>>& heights, vector<vector<bool>>& vis, int x, int y, int n, int m, int mid)
    {
        vis[x][y] = true;

        if (x == n - 1 && y == m - 1)
            return true;

        for (int i = 0; i < 4; i++)
        {
            int newx = x + dx[i];
            int newy = y + dy[i];

            if (isValid(newx, newy, n, m) && !vis[newx][newy] && abs(heights[newx][newy] - heights[x][y]) <= mid)
            {
                if (DFS(heights, vis, newx, newy, n, m, mid))
                    return true;
            }
        }

        return false;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();

        int low = 0, high = 1e6;

        while (low <= high)
        {
            int mid = (low + high) >> 1;
            
            vector<vector<bool>> vis(n, vector<bool> (m, false));

            if (DFS(heights, vis, 0, 0, n, m, mid))
                high = mid - 1;
            
            else
                low = mid + 1;
        }

        return low;
    }
};



