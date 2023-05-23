// Problem Link :- https://leetcode.com/problems/path-with-minimum-effort/

// Time Complexity :- O(4 * n * m * log(n * m))
// Space Complexity :- O(n * m)

class Solution {
public:

    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

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
                
                if (newx >= 0 && newx < n && newy >= 0 && newy < m)
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