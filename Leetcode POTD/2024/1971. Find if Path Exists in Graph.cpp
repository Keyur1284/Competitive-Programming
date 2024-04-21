// Problem Link :- https://leetcode.com/problems/find-if-path-exists-in-graph/

// Solved by DFS
// Time Complexity :- O(n + edges)
// Space Complexity :- O(n + edges)

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<int> adj[n];

        for (auto &it : edges)
        {
            adj[it[0]].emplace_back(it[1]);
            adj[it[1]].emplace_back(it[0]);
        }

        vector<bool> vis(n, false);

        function<void(int)> DFS = [&](int node) -> void
        {
            vis[node] = true;

            for (auto &child : adj[node])
            {
                if (!vis[child])
                    DFS(child);
            }
        };

        DFS(source);

        return vis[destination];
    }
};



class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<int> adj[n];

        for (auto &it : edges)
        {
            adj[it[0]].emplace_back(it[1]);
            adj[it[1]].emplace_back(it[0]);
        }

        vector<bool> vis(n, false);

        function<bool(int)> DFS = [&](int node) -> bool
        {
            if (node == destination)
                return true;

            vis[node] = true;

            for (auto &child : adj[node])
            {
                if (!vis[child])
                    if (DFS(child))
                        return true;
            }

            return false;
        };

        return DFS(source);
    }
};



// Solved by BFS
// Time Complexity :- O(n + edges)
// Space Complexity :- O(n + edges)

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<int> adj[n];

        for (auto &it : edges)
        {
            adj[it[0]].emplace_back(it[1]);
            adj[it[1]].emplace_back(it[0]);
        }

        vector<bool> vis(n, false);

        queue<int> q;
        q.emplace(source);
        vis[source] = true;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            if (node == destination)
                return true;

            for (auto &child : adj[node])
            {
                if (!vis[child])
                {
                    q.emplace(child);
                    vis[child] = true;
                }
            }
        }

        return false;
    }
};



// Solved by DSU
// Time Complexity :- O(n + edges)
// Space Complexity :- O(n)

class DSU {
private:

    vector<int> parent, rank, size;

public:

    DSU(int n)
    {
        for (int i = 0; i <= n; i++)
        {
            parent.emplace_back(i);
            rank.emplace_back(0);
            size.emplace_back(1);
        }
    }

    int findPar(int node)
    {
        if (node == parent[node])
            return node;

        return parent[node] = findPar(parent[node]);
    }

    void UnionRank(int u, int v)
    {
        u = findPar(u);
        v = findPar(v);

        if (u != v)
        {
            if (rank[u] < rank[v])
                parent[u] = v;

            else
                parent[v] = u;

            if (rank[u] == rank[v])
                rank[u]++;
        }
    }

    void UnionSize(int u, int v)
    {
        u = findPar(u);
        v = findPar(v);

        if (u != v)
        {
            if (size[u] < size[v])
            {
                parent[u] = v;
                size[v] += size[u];
            }

            else
            {
                parent[v] = u;
                size[u] += size[v];
            }
        }
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        DSU dsu(n - 1);

        for (auto &it : edges)
            dsu.UnionRank(it[0], it[1]);

        return dsu.findPar(source) == dsu.findPar(destination);
    }
};