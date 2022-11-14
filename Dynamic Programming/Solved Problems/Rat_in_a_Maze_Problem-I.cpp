//Problem Link :- https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void solve (int x, int y, vector<vector<int>> &m, int n, vector<string> &ans, vector <vector <int>> &vis, string temp)
    {
        if(x < 0 || y < 0 || x >= n || y >= n || m[x][y] == 0) 
            return;
        
        if (x == n - 1 && y == n - 1)
        {
            ans.emplace_back(temp);
            return;
        }
        
        int dx[] = {1, 0, 0, -1};
        int dy[] = {0, -1, 1, 0};
        string dir = "DLRU";
        
        for (int i = 0; i<4; i++)
        {
            int newx = x + dx[i];
            int newy = y + dy[i];
            
            if (newx >= 0 && newy >= 0 && newx < n && newy < n && m[newx][newy] == 1 && !vis[newx][newy])
            {
                vis[x][y] = 1;
                solve(newx, newy, m, n, ans, vis, temp + dir[i]);
                vis[x][y] = 0;
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
       
       vector<string> ans;
       vector <vector <int>> vis (n, vector <int> (n, 0));
       
       if (!m[n-1][n-1] || !m[0][0])
        return {};
        
       solve (0, 0, m, n, ans, vis, "");
       
       return ans;
    }
};

    
//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends