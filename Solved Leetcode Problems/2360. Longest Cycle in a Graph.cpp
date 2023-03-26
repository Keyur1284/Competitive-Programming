// Problem Link :- https://leetcode.com/problems/longest-cycle-in-a-graph/

// Time Complexity :- O(n)
// Space Complexity :- O(n)

// Solved by DFS

class Solution {
public:
    
    void DFS (int node, int &ans, vector<bool> &vis, unordered_map<int, int> &dist, vector<int> &edges)
    {
        vis[node] = true;
        int neighbour = edges[node];

        if (neighbour != -1)
        {
            if (!vis[neighbour])
            {
                dist[neighbour] = 1 + dist[node];
                DFS (neighbour, ans, vis, dist, edges);
            }

            else if (dist.find(neighbour) != dist.end())
                ans = max(ans, dist[node] - dist[neighbour] + 1);
        }
    }
    
    int longestCycle(vector<int>& edges) {
        
        int n = edges.size(), ans = -1;
        vector<bool> vis(n, false);

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                unordered_map<int, int> dist;
                dist[i] = 1;

                DFS (i, ans, vis, dist, edges);
            }
        }

        return ans;
    }
};


// Solved by Kahn's Algorithm

class Solution {
public:
    
    int longestCycle(vector<int>& edges) {
        
        int n = edges.size(), ans = -1;
        vector<bool> vis(n, false);
        vector<int> indegree(n, 0);

        for (auto &it : edges)
        {
            if (it != -1)
                indegree[it]++;
        }

        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
                q.emplace(i);
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            vis[node] = true;

            int neighbour = edges[node];

            if (neighbour != -1)
            {
                indegree[neighbour]--;

                if (indegree[neighbour] == 0)
                    q.emplace(neighbour);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                int neighbour = edges[i];
                int count = 1;
                vis[i] = true;

                while (neighbour != i)
                {
                    vis[neighbour] = true;
                    count++;
                    neighbour = edges[neighbour];
                }

                ans = max(ans, count);
            }
        }

        return ans;
    }
};