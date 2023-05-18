//Problem Link :- https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1

// Solved using DFS

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};
    
    void DFS (int x, int y, int n, int m, vector<vector<bool>> &vis, vector<vector<char>> &mat)
    {
        vis[x][y] = true;
        
        for (int i = 0; i < 4; i++)
        {
            int newx = x + dx[i];
            int newy = y + dy[i];
            
            if (newx >= 0 && newx < n && newy >= 0 && newy < m && mat[newx][newy] == 'O' && !vis[newx][newy])
                DFS (newx, newy, n, m, vis, mat);
        }
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> &mat)
    {
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((i * j == 0 || i == n - 1 || j == m - 1) && mat[i][j] == 'O' && !vis[i][j])
                    DFS (i, j, n, m, vis, mat);
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 'O' && !vis[i][j])
                    mat[i][j] = 'X';
            }
        }
        
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends


// Solved using Union Find

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


class Solution{
public:

    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

    vector<vector<char>> fill(int n, int m, vector<vector<char>> &mat)
    {
        DSU dsu(n * m);
        int boundary = m * n;
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((i * j == 0 || i == n - 1 || j == m - 1) && mat[i][j] == 'O')
                    dsu.UnionRank (i * m + j, boundary);
            }
        }
        
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = 1; j < m - 1; j++)
            {
                if (mat[i][j] == 'O')
                {
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int newx = i + dx[dir];
                        int newy = j + dy[dir];

                        if (mat[newx][newy] == 'O')
                            dsu.UnionRank(i * m + j, newx * m + newy);
                    }
                }
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 'O' && dsu.findPar(i * m + j) != dsu.findPar(boundary))
                    mat[i][j] = 'X';
            }
        }
        
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends