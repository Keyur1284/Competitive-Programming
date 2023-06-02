// Problem Link :- https://leetcode.com/problems/detonate-the-maximum-bombs/

// Solved by DFS
// Time Complexity :- O(N^3)
// Space Complexity :- O(N^2)

class Solution {
public:

    int DFS (int bomb, vector<bool> &vis, vector<int> adj[])
    {
        vis[bomb] = true;
        int count = 1;

        for (auto &it : adj[bomb])
        {
            if (!vis[it])
                count += DFS (it, vis, adj);
        }

        return count;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        
        int n = bombs.size();
        vector<int> adj[n];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    long xi = bombs[i][0], yi = bombs[i][1], ri = bombs[i][2];
                    long xj = bombs[j][0], yj = bombs[j][1];
                    long dis = pow(xi - xj, 2) + pow(yi - yj, 2);

                    if (dis <= pow(ri, 2))
                        adj[i].emplace_back(j);
                }
            }
        }

        int maxBombs = 0;

        for (int i = 0; i < n; i++)
        {
            vector<bool> vis (n, false);
            int bombs = DFS (i, vis, adj);

            maxBombs = max(maxBombs, bombs);
        }

        return maxBombs;
    }
};



// Solved by BFS
// Time Complexity :- O(N^3)
// Space Complexity :- O(N^2)

class Solution {
public:

    int BFS (int start, vector<bool> &vis, vector<int> adj[])
    {
        queue<int> q;
        q.emplace(start);
        vis[start] = true;
        int count = 1;

        while (!q.empty())
        {
            int bomb = q.front();
            q.pop();

            for (auto &it : adj[bomb])
            {
                if (!vis[it])
                {
                    q.emplace(it);
                    vis[it] = true;
                    count++;
                }
            }
        }

        return count;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        
        int n = bombs.size();
        vector<int> adj[n];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    long xi = bombs[i][0], yi = bombs[i][1], ri = bombs[i][2];
                    long xj = bombs[j][0], yj = bombs[j][1];
                    long dis = pow(xi - xj, 2) + pow(yi - yj, 2);

                    if (dis <= pow(ri, 2))
                        adj[i].emplace_back(j);
                }
            }
        }

        int maxBombs = 0;

        for (int i = 0; i < n; i++)
        {
            vector<bool> vis (n, false);
            int bombs = BFS (i, vis, adj);

            maxBombs = max(maxBombs, bombs);
        }

        return maxBombs;
    }
};