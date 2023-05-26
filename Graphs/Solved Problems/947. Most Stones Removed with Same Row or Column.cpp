// Problem Link :- https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

// Solved by Union Find  (Best Solution)
// Time Complexity :- O(N)
// Space Complexity :- O(maxRow + maxCol)

class DSU {

private:
    
    vector<int> parent, rank, size;

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
        {
            parent[u] = v;
        }

        else if (rank[u] > rank[v])
        {
            parent[v] = u;
        }

        else if (rank[u] == rank[v])
        {
            parent[v] = u;
            rank[u]++;
        }
    }

    void UnionSize (int u, int v)
    {
        u = findPar(u);
        v = findPar(v);

        if (u == v)
            return;

        if (size[u] < size[v])
        {
            parent[u] = v;
            size[v] += size[u];
        }

        else if (rank[u] >= rank[v])
        {
            parent[v] = u;
            size[u] += size[v];
        }
    }     
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        
        int n = stones.size();
        int maxRow = 0, maxCol = 0;

        for (auto &it : stones)
        {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        DSU dsu(maxRow + maxCol + 1);
        unordered_set<int> st;

        for (auto &it : stones)
        {
            int rowNode = it[0];
            int colNode = it[1] + maxRow + 1;

            dsu.UnionSize(rowNode, colNode);
            st.emplace(rowNode);
            st.emplace(colNode);
        }

        int components = 0;

        for (auto &it : st)
        {
            if (dsu.findPar(it) == it)
                components++;
        }

        return n - components;
    }
};



// Solved by Union Find
// Time Complexity :- O(N^2)
// Space Complexity :- O(N)

class DSU {

private:
    
    vector<int> parent, rank, size;

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
        {
            parent[u] = v;
        }

        else if (rank[u] > rank[v])
        {
            parent[v] = u;
        }

        else if (rank[u] == rank[v])
        {
            parent[v] = u;
            rank[u]++;
        }
    }

    void UnionSize (int u, int v)
    {
        u = findPar(u);
        v = findPar(v);

        if (u == v)
            return;

        if (size[u] < size[v])
        {
            parent[u] = v;
            size[v] += size[u];
        }

        else if (rank[u] >= rank[v])
        {
            parent[v] = u;
            size[u] += size[v];
        }
    }     
};

class Solution {
public:

    bool isValid (vector<int> &stn1, vector<int> &stn2)
    {
        return (stn1[0] == stn2[0] || stn1[1] == stn2[1]); 
    }

    int removeStones(vector<vector<int>>& stones) {
        
        int n = stones.size();
        DSU dsu(n - 1);
        int components = n;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (isValid(stones[i], stones[j]) && dsu.findPar(i) != dsu.findPar(j))
                {
                    dsu.UnionSize (i, j);
                    components--;
                }
            }
        }

        return n - components;
    }
};



// Solved by DFS
// Time Complexity :- O(N^2)
// Space Complexity :- O(N)

class Solution {
public:

    bool isValid (vector<int> &stn1, vector<int> &stn2)
    {
        return (stn1[0] == stn2[0] || stn1[1] == stn2[1]); 
    }

    void DFS (int node, vector<bool> &vis, vector<int> adj[])
    {
        vis[node] = true;

        for (auto &it : adj[node])
        {
            if (!vis[it])
                DFS (it, vis, adj);
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        
        int n = stones.size();
        vector<int> adj[n];

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (isValid(stones[i], stones[j]))
                {
                    adj[i].emplace_back(j);
                    adj[j].emplace_back(i);
                }
            }
        }

        vector<bool> vis (n, false);

        int components = 0;

        for (int node = 0; node < n; node++)
        {
            if (!vis[node])
            {
                DFS (node, vis, adj);
                components++;
            }
        }

        return n - components;
    }
};