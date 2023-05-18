//Problem Link :- https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    
    struct Node {
        
        int x, y, dist;
        
        Node (int a, int b, int c)
        {
            x = a;
            y = b;
            dist = c;
        }
    };
    
    //Function to find distance of nearest 1 in the grid for each cell.
	
	
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size();
	    int m = grid[0].size();
	    int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
	    
	    vector <vector <int>> vis (n, vector <int> (m, 0)), ans (n, vector <int> (m, 0));
	    queue <Node> q;
	    
	    for (int i = 0; i < n; i++)
	    {
	        for (int j = 0; j < m; j++)
	        {
	            if (grid[i][j] == 1)
	            {
	                vis[i][j] = 1;
	                q.emplace(Node(i, j, 0));
	            }
	        }
	    }
	    
	    while (!q.empty())
	    {
	        int i = q.front().x;
	        int j = q.front().y;
	        int steps = q.front().dist;
	        q.pop();
	        
	        ans[i][j] = steps;
	        
	        for (int it = 0; it < 4; it++)
	        {
	            int newx = i + dx[it];
	            int newy = j + dy[it];
	            
	            if (newx >= 0 && newx < n && newy >= 0 && newy < m && !vis[newx][newy])
	            {
	                vis[newx][newy] = 1;
	                q.emplace(Node(newx, newy, steps + 1));
	            }
	        }
	        
	    }
	    
    	return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size();
	    int m = grid[0].size();
	    
	    vector<vector<int>> ans (n, vector<int> (m, INT_MAX));

	    queue<vector<int>> q;
	    
	    for (int i = 0; i < n; i++)
	    {
	        for (int j = 0; j < m; j++)
	        {
	            if (grid[i][j])
	            {
	                ans[i][j] = 0;
	                q.push({i, j});
	            }
	        }
	    }
	    
	    while (!q.empty())
	    {
	        auto it = q.front();
	        int x = it[0], y = it[1];
	        q.pop();
	        
	        for (int i = 0; i < 4; i++)
	        {
	            int newx = x + dx[i];
	            int newy = y + dy[i];
	            
	            if (newx >= 0 && newx < n && newy >= 0 && newy < m && ans[newx][newy] > ans[x][y] + 1)
	            {
	                ans[newx][newy] = ans[x][y] + 1;
	                q.push({newx, newy});
	            }
	        }
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends