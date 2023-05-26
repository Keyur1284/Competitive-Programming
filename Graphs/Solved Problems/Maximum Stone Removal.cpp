// Problem Link :- https://practice.geeksforgeeks.org/problems/maximum-stone-removal-1662179442/1

// Solved by Union Find  (Best Solution)
// Time Complexity :- O(N)
// Space Complexity :- O(maxRow + maxCol)

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

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
    int maxRemove(vector<vector<int>>& stones, int n) {
        
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

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends