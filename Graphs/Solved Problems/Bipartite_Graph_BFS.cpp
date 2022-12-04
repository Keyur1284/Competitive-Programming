//Problem Link :- https://practice.geeksforgeeks.org/problems/bipartite-graph/1


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	
	bool bipartiteBFS (int node, vector <int> &color, vector<int>adj[])
	{
	    color[node] = 1;
	    
	    queue <int> q;
	    q.emplace(node);
	    
	    while (!q.empty())
	    {
	        int temp = q.front();
	        q.pop();
	        
	        for (auto it : adj[temp])
	        {
	            if (color[it] == -1)
	            {
	                color[it] = 1 - color[temp];
	                q.emplace(it);
	            }
	            
	            else if (color[it] == color[temp])
	                return false;
	        }
	    }
	    
	    return true;
	}
	
	bool isBipartite(int v, vector<int>adj[]){
	    
	    vector <int> color (v, -1);
	    
	    for (int i = 0; i < v; i++)
	    {
	        if (color[i] == -1)
	            if (bipartiteBFS(i, color, adj) == false)
	                return false;
	    }
	    
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends