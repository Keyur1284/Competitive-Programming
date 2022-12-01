//Problem Link :- https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    
    int dx[8] = {1, 0, -1, 0, -1, -1, 1, 1};
    int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};
    
    void DFS (int i, int j, int row, int col, vector <vector <char>> &grid)
    {
        
        if (i >= 0 && i < row && j >= 0 && j < col && grid[i][j] == '1')
       {
            grid[i][j] = '0';
            
            for (int dir = 0; dir < 8; dir++)
            {
                DFS (i + dx[dir], j + dy[dir], row, col, grid);
            }
       }
        
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;
        
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == '1')
                {
                    DFS(i, j, row, col, grid);
                    ans++;
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends