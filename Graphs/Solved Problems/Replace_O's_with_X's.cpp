//Problem Link :- https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    void DFS (int i, int j, int n, int m, vector<vector<char>>& mat, vector <vector<int>> &vis)
    {
        vis[i][j] = 1;

        for (int it = 0; it < 4; it++)
        {
            int newx = i + dx[it];
            int newy = j + dy[it];

            if (newx >= 0 && newy >= 0 && newx < n && newy < m && !vis[newx][newy] && mat[newx][newy] == 'O')
                DFS (newx, newy, n, m, mat, vis);
        }
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector <vector <int>> vis (n, vector <int> (m, 0));
        
        for (int i = 0; i < n; i++)
        {
            if (mat[i][0] == 'O' && !vis[i][0])
                DFS (i, 0, n, m, mat, vis);
                
            if (mat[i][m - 1] == 'O' && !vis[i][m - 1])
                DFS (i, m - 1, n, m, mat, vis);
        }
        
        for (int j = 0; j < m; j++)
        {
            if (mat[0][j] == 'O' && !vis[0][j])
                DFS (0, j, n, m, mat, vis);
                
            if (mat[n - 1][j] == 'O' && !vis[n - 1][j])
                DFS (n - 1, j, n, m, mat, vis);
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