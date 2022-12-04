//Problem Link :- https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1


//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    void DFS (int x, int y, int basex, int basey, int n, int m, vector <pair<int, int>> &vec, vector <vector <int>> &vis, vector<vector<int>>& grid)
    {
        vis[x][y] = 1;
        
        vec.emplace_back(x - basex, y - basey);
        
        for (int it = 0; it < 4; it++)
        {
            int newx = x + dx[it];
            int newy = y + dy[it];
            
            if (newx >= 0 && newy >= 0 && newx < n && newy < m && !vis[newx][newy] && grid[newx][newy] == 1)
                DFS (newx, newy, basex, basey, n, m, vec, vis, grid);
        }
    }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector <vector <int>> vis (n, vector <int> (m, 0));
        set <vector <pair <int, int>>> s;
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    vector <pair<int, int>> vec;
                    DFS (i, j, i, j, n, m, vec, vis, grid);
                    
                    s.emplace(vec);
                }
                
            }
        }
        
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends