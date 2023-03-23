// Problem Link :- https://leetcode.com/problems/number-of-operations-to-make-network-connected/

// Time Complexity :- O(n + e)
// Space Complexity :- O(n + e)

// Solved by DFS

class Solution {
public:

    void DFS (int node, vector<bool> &vis, vector<int> adj[])
    {
        vis[node] = true;

        for (auto &neighbour : adj[node])
            if (!vis[neighbour])
                DFS (neighbour, vis, adj);
    }

    int makeConnected(int n, vector<vector<int>>& connections) {

        vector<int> adj[n];
        vector<bool> vis(n, false);
        int count = 0;
        int cables = connections.size();

        for (auto &it : connections)
        {
            adj[it[0]].emplace_back(it[1]);
            adj[it[1]].emplace_back(it[0]);
        }

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                DFS (i, vis, adj);
                count++;
            }
        }   

        return (cables >= n - 1) ? count - 1 : -1;     
    }
};


// Solved by BFS

class Solution {
public:

    void BFS (int node, vector<bool> &vis, vector<int> adj[])
    {
        queue<int> q;
        q.emplace(node);
        vis[node] = true;

        while (!q.empty())
        {
            int Node = q.front();
            q.pop();

            for (auto &neighbour : adj[Node])
                if (!vis[neighbour])
                {
                    vis[neighbour] = true;
                    q.emplace(neighbour);
                }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {

        vector<int> adj[n];
        vector<bool> vis(n, false);
        int count = 0;
        int cables = connections.size();

        for (auto &it : connections)
        {
            adj[it[0]].emplace_back(it[1]);
            adj[it[1]].emplace_back(it[0]);
        }

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                BFS (i, vis, adj);
                count++;
            }
        }   

        return (cables >= n - 1) ? count - 1 : -1;     
    }
};


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

    int makeConnected(int n, vector<vector<int>>& connections) {
        
        DSU dsu(n - 1);
        int count = n;
        int cables = connections.size();

        for (auto &it : connections)
        {
            if (dsu.findPar(it[0]) != dsu.findPar(it[1]))
            {
                count--;
                dsu.UnionRank(it[0], it[1]);
            }
        }
   
        return (cables >= n - 1) ? count - 1 : -1;     
    }
};