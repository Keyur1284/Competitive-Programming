//Problem Link :- https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1


//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
    
    void DFS (int x, int y, int basex, int basey, int n, int m, vector<vector<bool>> &vis, 
            vector<vector<int>> &vec, vector<vector<int>>& grid)
    {
        vis[x][y] = true;
        vec.push_back({x - basex, y - basey});
        
        for (int i = 0; i < 4; i++)
        {
            int newx = x + dx[i];
            int newy = y + dy[i];
            
            if (newx >= 0 && newx < n && newy >= 0 && newy < m && grid[newx][newy] && !vis[newx][newy])
                DFS (newx, newy, basex, basey, n, m, vis, vec, grid);
        }
    }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> vis (n, vector<bool> (m, false));
        set<vector<vector<int>>> st;
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] && !vis[i][j])
                {
                    vector<vector<int>> vec;
                    
                    DFS (i, j, i, j, n, m, vis, vec, grid);
                    st.emplace(vec); 
                }
            }
        }
        
        return (int)st.size();
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