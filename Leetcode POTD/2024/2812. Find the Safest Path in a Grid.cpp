// Problem Link :- https://leetcode.com/problems/find-the-safest-path-in-a-grid/

// Solved by BFS + Binary Search
// Time Complexity :- O(n^2 * logn)
// Space Complexity :- O(n^2)

class Solution {
public:

    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};

    bool isValid(int x, int y, int &n)
    {
        return (x >= 0 && y >= 0 && x < n && y < n);
    }

    bool isSafenessPossible(int safenessFactor, int &n, vector<vector<int>> &grid)
    {
        if (grid[0][0] < safenessFactor || grid[n - 1][n - 1] < safenessFactor)
            return false;

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        q.emplace(0, 0);
        visited[0][0] = true;

        while (!q.empty()) 
        {
            auto curr = q.front();
            int x = curr.first, y = curr.second;
            q.pop();

            if (curr.first == n - 1 && curr.second == n - 1)
                return true; 

            for (int k = 0; k < 4; k++)
            {
                int newx = x + dx[k], newy = y + dy[k];

                if (isValid(newx, newy, n) && !visited[newx][newy] && grid[newx][newy] >= safenessFactor)
                {
                    visited[newx][newy] = true;
                    q.emplace(newx, newy);
                }
            }
        }

        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        
        int n = grid.size();
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    q.emplace(i, j);
                    grid[i][j] = 0;
                }

                else
                    grid[i][j] = -1;
            }
        }

        while (!q.empty())
        {
            int size = q.size();

            while(size--)
            {
                auto curr = q.front();
                int x = curr.first, y = curr.second;
                int currDist = grid[x][y];
                q.pop();

                for (int k = 0; k < 4; k++)
                {
                    int newx = x + dx[k], newy = y + dy[k];

                    if (isValid(newx, newy, n) && grid[newx][newy] == -1)
                    {
                        grid[newx][newy] = currDist + 1;
                        q.emplace(newx, newy);
                    }
                }
            }
        }

        int low = 0, high = -1, ans = -1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                high = max(high, grid[i][j]);
            }
        }

        while (low <= high)
        {
            int mid = (low + high) >> 1;

            if (isSafenessPossible(mid, n, grid))
            {
                ans = mid;
                low = mid + 1;
            }

            else
                high = mid - 1;
        }

        return ans;
    }
};



class Solution {
public:

    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};

    bool isValid(int x, int y, int &n)
    {
        return (x >= 0 && y >= 0 && x < n && y < n);
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        
        int n = grid.size();
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    q.emplace(i, j);
                    grid[i][j] = 0;
                }

                else
                    grid[i][j] = -1;
            }
        }

        while (!q.empty())
        {
            int size = q.size();

            while(size--)
            {
                auto curr = q.front();
                int x = curr.first, y = curr.second;
                int currDist = grid[x][y];
                q.pop();

                for (int k = 0; k < 4; k++)
                {
                    int newx = x + dx[k], newy = y + dy[k];

                    if (isValid(newx, newy, n) && grid[newx][newy] == -1)
                    {
                        grid[newx][newy] = currDist + 1;
                        q.emplace(newx, newy);
                    }
                }
            }
        }

        priority_queue<vector<int>> pq;
        pq.push({grid[0][0], 0, 0});
        grid[0][0] = -1;

        while (!pq.empty()) 
        {
            auto curr = pq.top();
            int safenessFactor = curr[0], x = curr[1], y = curr[2];
            pq.pop();

            if (x == n - 1 && y == n - 1)
                return safenessFactor;

            for (int k = 0; k < 4; k++) 
            {
                int newx = x + dx[k], newy = y + dy[k];

                if (isValid(newx, newy, n) && grid[newx][newy] != -1) 
                {
                    pq.push({min(curr[0], grid[newx][newy]), newx, newy});
                    grid[newx][newy] = -1;
                }
            }
        }

        return -1;
    }
};