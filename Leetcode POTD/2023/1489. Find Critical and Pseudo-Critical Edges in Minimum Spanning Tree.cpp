// Problem Link :- https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/

// Solved by Kruskal's Algorithm (Union Find)
// Time Complexity :- O(mlogm + (m ^ 2 ) * alpha(n))    m -> edges.size() , alpha(n) -> Inverse Ackermann Function
// Space Complexity :- O(m + n)

class DSU {
private:

    int components;    
    vector<int> parent, size;

public:

    DSU (int n)
    {
        components = n + 1;

        for (int i = 0; i <= n; i++)
        {
            parent.emplace_back(i);
            size.emplace_back(1);
        }
    }

    int findPar (int node)
    {
        if (node == parent[node])
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

        components--;
    }  

    int getComponents ()
    {
        return components;
    } 
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        
        int m = edges.size();

        for (int i = 0; i < m; i++)
            edges[i].emplace_back(i);

        sort (edges.begin(), edges.end(), [&](vector<int> &u, vector<int> &v){
            return u[2] < v[2];
        });

        int mst = 0;
        DSU dsu(n - 1);

        for (int i = 0; i < m; i++)
        {
            int wt = edges[i][2], u = edges[i][0], v = edges[i][1];

            if (dsu.findPar(u) != dsu.findPar(v))
            {
                mst += wt;
                dsu.UnionSize(u, v);
            }
        }

        vector<vector<int>> ans(2);

        for (int i = 0; i < m; i++)
        {
            DSU ignore(n - 1);
            int ignoreSum = 0, edgeIndex = edges[i][3];

            for (int j = 0; j < m; j++)
            {
                if (i != j)
                {
                    int wt = edges[j][2], u = edges[j][0], v = edges[j][1];

                    if (ignore.findPar(u) != ignore.findPar(v))
                    {
                        ignoreSum += wt;
                        ignore.UnionSize(u, v);
                    }
                }
            }

            int components = ignore.getComponents();

            if (components > 1 || ignoreSum > mst)
            {
                ans[0].emplace_back(edgeIndex);
            }

            else
            {
                DSU force(n - 1);
                int forceSum = edges[i][2], edgeIndex = edges[i][3];
                force.UnionSize(edges[i][0], edges[i][1]);

                for (int j = 0; j < m; j++)
                {
                    if (i != j)
                    {
                        int wt = edges[j][2], u = edges[j][0], v = edges[j][1];

                        if (force.findPar(u) != force.findPar(v))
                        {
                            forceSum += wt;
                            force.UnionSize(u, v);
                        }
                    }
                }

                if (forceSum == mst)
                {
                    ans[1].emplace_back(edgeIndex);
                }
            }
        }

        return ans;
    }
};