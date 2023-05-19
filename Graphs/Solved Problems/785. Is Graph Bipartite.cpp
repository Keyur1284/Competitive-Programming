// Problem Link :- https://leetcode.com/problems/is-graph-bipartite/

// Time Complexity :- O(N + E)
// Space Complexity :- O(N)

// Solved by DFS

class Solution {
public:

    bool checkBipartite (int node, vector<int> &color, vector<vector<int>>& graph)
    {
        if (color[node] == -1)
            color[node] = 1;

        for (auto &it : graph[node])
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[node];

                if (!checkBipartite(it, color, graph))
                    return false;
            }

            else if (color[it] == color[node])
                return false;
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> color (n, -1);

        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                if (!checkBipartite(i, color, graph))
                    return false;
            }
        }

        return true;
    }
};


// Solved by BFS

class Solution {
public:

    bool checkBipartite (int val, vector<int> &color, vector<vector<int>>& graph)
    {
        queue<int> q;
        q.emplace(val);
        color[val] = 1;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto &it : graph[node])
            {
                if (color[it] == -1)
                {
                    color[it] = 1 - color[node];
                    q.emplace(it);
                }

                else if (color[it] == color[node])
                    return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> color (n, -1);

        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                if (!checkBipartite(i, color, graph))
                    return false;
            }
        }

        return true;
    }
};


// Solved by Union Find

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

    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        DSU dsu(n - 1);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < graph[i].size(); j++)
            {
                if (dsu.findPar(i) == dsu.findPar(graph[i][j]))
                    return false;

                dsu.UnionRank(graph[i][j], graph[i][0]);
            }
        }

        return true;
    }
};