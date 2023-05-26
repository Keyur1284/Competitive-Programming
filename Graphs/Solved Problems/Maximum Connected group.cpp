// Problem Link :- https://practice.geeksforgeeks.org/problems/maximum-connected-group/1

// Solved by Union Find
// Time Complexity :- O(N^2)
// Space Complexity :- O(N^2)

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

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

    int getSize (int u)
    {
        return size[u];
    } 
    
};

class Solution {
  public:
  
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
  
    int MaxConnection(vector<vector<int>>& grid) {
        
        int n = grid.size();
        DSU dsu (n * n - 1);
        
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < n; y++)
            {
                if (grid[x][y])
                {
                    for (int i = 0; i < 4; i++)
                    {
                        int newx = x + dx[i];
                        int newy = y + dy[i];
                        
                        if (newx >= 0 && newx < n && newy >= 0 && newy < n && grid[newx][newy])
                        {
                            dsu.UnionSize(x * n + y, newx * n + newy);
                        }
                    }
                }
            }
        }
        
        int maxArea = 0;
        
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < n; y++)
            {
                if (!grid[x][y])
                {
                    unordered_set<int> components;
                    
                    for (int i = 0; i < 4; i++)
                    {
                        int newx = x + dx[i];
                        int newy = y + dy[i];
                        
                        if (newx >= 0 && newx < n && newy >= 0 && newy < n && grid[newx][newy])
                        {
                            int parent = dsu.findPar(newx * n + newy);
                            components.emplace(parent);
                        }
                    }
                    
                    int area = 1;
                    
                    for (auto &it : components)
                    {
                        area += dsu.getSize(it);
                    }
                    
                    maxArea = max(maxArea, area);
                }
            }
        }
        
        for (int i = 0; i < n * n; i++)
        {
            maxArea = max(maxArea, dsu.getSize(i));
        }
        
        return maxArea;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends