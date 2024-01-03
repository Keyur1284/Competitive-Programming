// Problem Link :- https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/


// Time Complexity :- O(n + e)
// Space Complexity :- O(n + e)

// Solved by DFS

class Solution {
public:

    void DFS (int node, int &ans, vector<bool> &vis, vector<pair<int, int>> adj[])
    {
        vis[node] = true;
        
        for (auto &neighbour : adj[node])
        {
            ans = min (ans, neighbour.second);

            if(!vis[neighbour.first])
                DFS (neighbour.first, ans, vis, adj);
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<pair<int, int>> adj[n + 1];
        vector<bool> vis (n + 1, false);
        int ans = INT_MAX;

        for (auto &it : roads)
        {
            adj[it[0]].emplace_back(it[1], it[2]);
            adj[it[1]].emplace_back(it[0], it[2]);
        }

        DFS (1, ans, vis, adj);

        return ans;
    }
};


// Solved by BFS

class Solution {
public:

    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<pair<int, int>> adj[n + 1];
        vector<bool> vis (n + 1, false);
        int ans = INT_MAX;

        for (auto &it : roads)
        {
            adj[it[0]].emplace_back(it[1], it[2]);
            adj[it[1]].emplace_back(it[0], it[2]);
        }

        queue<int> q;
        q.emplace(1);
        vis[1] = true;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto &neighbour : adj[node])
            {
                ans = min(ans, neighbour.second);

                if (!vis[neighbour.first])
                {
                    q.emplace(neighbour.first);
                    vis[neighbour.first] = true;
                }
            }
        }

        return ans;
    }
};


// Time Complexity :- O(n + e)
// Space Complexity :- O(n)

// Solved by DSU 

class DSU 
{
    private:
        vector<int> parent, size, rank;
    
    public:
        DSU (int n) 
        {
            for (int i = 0; i <= n; i++)
            {
                parent.emplace_back(i);
                size.emplace_back(1);
                rank.emplace_back(0);
            }
        }

        int findPar(int node)
        {
            if(node == parent[node])
                return node;

            return parent[node] = findPar(parent[node]);
        }
    
        void UnionRank(int u, int v)
        {
            u = findPar(u);
            v = findPar(v);

            if (u == v)
                return;

            if(rank[u] < rank[v])
                parent[u] = v;

            else if (rank[v] < rank[u])
                parent[v] = u;

            else if (rank[u] == rank[v])
            {
                parent[v] = u;
                rank[u]++;
            }
        }

        void UnionSize(int u, int v)
        {
            u = findPar(u);
            v = findPar(v);

            if(u == v)
                return;

            else if (size[u] < size[v])
            {
                parent[u] = v;
                size[v] += size[u];
            }

            else if (size[u] >= size[v])
            {
                parent[v] = u;
                size[u] += size[v];
            }
        }
};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        DSU dsu(n);
        int ans = INT_MAX;

        for (auto &it : roads)
            dsu.UnionRank(it[0], it[1]);

        for (auto &it : roads)
        {
            if (dsu.findPar(1) == dsu.findPar(it[0]))
                ans = min(ans, it[2]);
        }

        return ans;
    }
};