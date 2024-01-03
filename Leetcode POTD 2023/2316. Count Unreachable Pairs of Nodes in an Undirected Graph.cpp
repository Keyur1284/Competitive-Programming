// Problem Link :- https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/

// Time Complexity :- O(n + e)
// Space Complexity :- O(n + e)

// Solved by DFS

class Solution {
public:

    long long DFS (int node, vector<bool> &vis, vector<int> adj[])
    {
        long long count = 1;
        vis[node] = true;

        for (auto &neighbour : adj[node])
        {
            if (!vis[neighbour])
            {
                count += DFS(neighbour, vis, adj);
            }
        }
        
        return count;
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        long long total = n, ans = 0;
        vector<int> adj[n];
        vector<bool> vis(n, false);

        for (auto &it : edges)
        {
            adj[it[0]].emplace_back(it[1]);
            adj[it[1]].emplace_back(it[0]);
        }

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                long long count = DFS (i, vis, adj);
                ans += count * (total - count);
                total -= count;
            }
        }

        return ans;
    }
};


// Solved by BFS

class Solution {
public:

    long long BFS (int root, vector<bool> &vis, vector<int> adj[])
    {
        queue<int> q;
        q.emplace(root);
        long long count = 1;
        vis[root] = true;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto &neighbour : adj[node])
            {
                if (!vis[neighbour])
                {
                    q.emplace(neighbour);
                    count++;
                    vis[neighbour] = true;
                }
            }
        }
        
        return count;
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        long long total = n, ans = 0;
        vector<int> adj[n];
        vector<bool> vis(n, false);

        for (auto &it : edges)
        {
            adj[it[0]].emplace_back(it[1]);
            adj[it[1]].emplace_back(it[0]);
        }

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                long long count = BFS (i, vis, adj);
                ans += count * (total - count);
                total -= count;
            }
        }

        return ans;
    }
};


// Solved by DSU

class DSU {
    
    private:
    
    vector<int> parent, size, rank;

    public:

    DSU (int n)
    {
        for (int i = 0; i <= n; i++)
        {
            parent.emplace_back(i);
            rank.emplace_back(0);
            size.emplace_back(1);
        }
    }

    int findPar (int node)
    {
        if (node == parent[node])
            return node;

        return parent[node] = findPar(parent[node]);
    }

    void UnionRank (int u, int v)
    {
        u = findPar(u);
        v = findPar(v);

        if (u == v)
            return;

        if (rank[u] < rank[v])
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
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        DSU dsu(n - 1);

        for (auto &it : edges)
            dsu.UnionRank(it[0], it[1]);

        unordered_map<int, int> components;

        for (int i = 0; i < n; i++)
            components[dsu.findPar(i)]++;

        long long total = n, ans = 0;

        for (auto &it : components)
        {
            int size = it.second;
            ans += size * (total - size);
            total -= size;
        }
        
        return ans;
    }
};