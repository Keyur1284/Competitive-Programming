// Problem Link :- https://leetcode.com/problems/largest-color-value-in-a-directed-graph/

// Time Complexity :- O(n + m)
// Space Complexity :- O(n + m)

// Solved by DFS

class Solution {
public:

    int DFS (int node, vector<bool> &vis, vector<bool> &dfsVis, vector<vector<int>> &freq, string &colors, vector<int> adj[])
    {
        if (dfsVis[node])
            return INT_MAX;

        if (vis[node])
            return freq[node][colors[node] - 'a'];

        vis[node] = true;
        dfsVis[node] = true;

        for (auto &neighbors : adj[node])
        {
            if (DFS(neighbors, vis, dfsVis, freq, colors, adj) == INT_MAX)
                return INT_MAX;

            for (int i = 0; i < 26; i++)
                freq[node][i] = max(freq[node][i], freq[neighbors][i]);
        }

        freq[node][colors[node] - 'a']++;
        dfsVis[node] = false;

        return freq[node][colors[node] - 'a'];
    }

    int largestPathValue(string &colors, vector<vector<int>>& edges) {
        
        int n = colors.size(), ans = 0;

        vector<int> adj[n];
        vector<bool> vis(n, false), dfsVis(n, false);
        vector<vector<int>> freq(n, vector<int> (26, 0));

        for (auto &it : edges)
            adj[it[0]].emplace_back(it[1]);

        for (int node = 0; node < n; node++)
            ans = max(ans, DFS(node, vis, dfsVis, freq, colors, adj));

        return (ans == INT_MAX) ? -1 : ans;
    }
};


// Solved by BFS

class Solution {
public:

    int DFS (int node, vector<bool> &vis, vector<bool> &dfsVis, vector<vector<int>> &freq, string &colors, vector<int> adj[])
    {
        if (dfsVis[node])
            return INT_MAX;

        if (vis[node])
            return freq[node][colors[node] - 'a'];

        vis[node] = true;
        dfsVis[node] = true;

        for (auto &neighbors : adj[node])
        {
            if (DFS(neighbors, vis, dfsVis, freq, colors, adj) == INT_MAX)
                return INT_MAX;

            for (int i = 0; i < 26; i++)
                freq[node][i] = max(freq[node][i], freq[neighbors][i]);
        }

        freq[node][colors[node] - 'a']++;
        dfsVis[node] = false;

        return freq[node][colors[node] - 'a'];
    }

    int largestPathValue(string &colors, vector<vector<int>>& edges) {
        
        int n = colors.size(), ans = 0, visNodes = 0;

        vector<int> adj[n], indegree(n, 0);
        vector<vector<int>> freq(n, vector<int> (26, 0));

        for (auto &it : edges)
        {
            adj[it[0]].emplace_back(it[1]);
            indegree[it[1]]++;
        }
            
        queue<int> q;

        for (int node = 0; node < n; node++)
        {
            if (indegree[node] == 0)
                q.emplace(node);
        }
        
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            visNodes++;
            freq[node][colors[node] - 'a']++;

            ans = max(ans, freq[node][colors[node] - 'a']);

            for (auto &neighbors : adj[node])
            {
                for (int i = 0; i < 26; i++)
                    freq[neighbors][i] = max(freq[neighbors][i], freq[node][i]);

                indegree[neighbors]--;

                if (indegree[neighbors] == 0)
                    q.emplace(neighbors);
            }
        }

        return (visNodes != n) ? -1 : ans;
    }
};