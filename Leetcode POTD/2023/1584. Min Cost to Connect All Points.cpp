// Problem Link :- https://leetcode.com/problems/min-cost-to-connect-all-points/

// Solved by Kruskal's Algorithm
// Time Complexity :- O(ElogE) + O(ElogV) + O(E) = O(ElogE) = O(ElogV) (E = Edges, V = Vertices)
// Space Complexity :- O(E) + O(V) = O(E) (E = Edges, V = Vertices)

class DSU {
private:
    
    vector<int> parent, size;

public:

    DSU (int n)
    {
        for (int i = 0; i <= n; i++)
        {
            parent.emplace_back(i);
            size.emplace_back(1);
        }
    }

    int findPar (int node)
    {
        if (parent[node] == node)
            return node;
        
        return parent[node] = findPar(parent[node]);
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

        else
        {
            parent[v] = u;
            size[u] += size[v];
        }
    }
};

class Solution {
public:

    int findWeight (vector<int> &u, vector<int> &v)
    {
        return abs(u[0] - v[0]) + abs(u[1] - v[1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        vector<vector<int>> edges;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int weight = findWeight(points[i], points[j]);
                edges.push_back({weight, i, j});
            }
        }

        DSU dsu(n - 1);
        int mst = 0;

        sort(edges.begin(), edges.end());

        for (int i = 0; i < (n * (n - 1)/2); i++)
        {
            int wt = edges[i][0], u = edges[i][1], v = edges[i][2];

            if (dsu.findPar(u) != dsu.findPar(v))
            {
                mst += wt;
                dsu.UnionSize(u, v);
            }
        }

        return mst;
    }
};



// Solved by Prim's Algorithm
// Time Complexity :- O(ElogE) + O(ElogV) + O(E) = O(ElogE) = O(ElogV) (E = Edges, V = Vertices)
// Space Complexity :- O(E) + O(V) = O(E) (E = Edges, V = Vertices)

class Solution {
public:

    int findWeight (vector<int> &u, vector<int> &v)
    {
        return abs(u[0] - v[0]) + abs(u[1] - v[1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        vector<pair<int, int>> adj[n];

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int weight = findWeight(points[i], points[j]);
                adj[i].emplace_back(weight, j);
                adj[j].emplace_back(weight, i);
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, 0);
        vector<bool> vis(n, false);
        int mst = 0;

        while (!pq.empty())
        {
            auto it = pq.top();
            int wt = it.first, node = it.second;
            pq.pop();

            if (!vis[node])
            {
                vis[node] = true;
                mst += wt;

                for (auto &it : adj[node])
                {
                    pq.emplace(it.first, it.second);
                }
            }
        }

        return mst;
    }
};