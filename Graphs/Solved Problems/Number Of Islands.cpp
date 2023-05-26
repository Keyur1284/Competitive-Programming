// Problem Link :- https://practice.geeksforgeeks.org/problems/number-of-islands/1

// Solved by Union Find
// Time Complexity :- O(4 * alpha * Q)
// Space Complexity :- O(N * M)

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
};

class Solution {
  public:
  
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, -1, 1};
  
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        
        DSU dsu(n * m - 1);
        int count = 0;
        vector<int> ans;
        
        vector<vector<bool>> vis (n, vector<bool> (m, false));
        
        for (auto &it : operators)
        {
            int x = it[0];
            int y = it[1];
            
            if (vis[x][y])
            {
                ans.emplace_back(count);
                continue;
            }
            
            vis[x][y] = true;
            count++;
            
            for (int i = 0; i < 4; i++)
            {
                int newx = x + dx[i];
                int newy = y + dy[i];
                
                if (newx >= 0 && newx < n && newy >= 0 && newy < m && vis[newx][newy])
                {
                    if (dsu.findPar(x * m + y) != dsu.findPar(newx * m + newy))
                    {
                        dsu.UnionSize(x * m + y, newx * m + newy);
                        count--;
                    }
                }
            }
            
            ans.emplace_back(count);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends



// Solved by DFS
// Time Complexity :- O(Q * N * M)
// Space Complexity :- O(N * M)

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, -1, 1};
    
    void DFS (int x, int y, int n, int m, vector<vector<int>> &grid)
    {
        grid[x][y] = 0;
        
        for (int i = 0; i < 4; i++)
        {
            int newx = x + dx[i];
            int newy = y + dy[i];
            
            if (newx >= 0 && newx < n && newy >= 0 && newy < m && grid[newx][newy])
                DFS (newx, newy, n, m, grid);
        }
    }
  
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        
        vector<int> ans;
    
        vector<vector<int>> grid (n, vector<int> (m, 0));
    
        for (auto &it : operators)
        {
            int x = it[0];
            int y = it[1];
            
            grid[x][y] = 1;
            
            vector<vector<int>> newGrid = grid;
            int count = 0;
            
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (newGrid[i][j])
                    {
                        DFS (i, j, n, m, newGrid);
                        count++;
                    }
                }
            }
            
            ans.emplace_back(count);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends