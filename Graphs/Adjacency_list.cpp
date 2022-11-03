#include <bits/stdc++.h>
using namespace std;

int main() {

    // n = no. of vertices    m = no. of edges
	int n, m;
	cin >> n >> m; 
	
	// declare the adjacent matrix 
	vector<int> adj[n+1]; 
	
	// take edges as input 
	for(int i = 0; i<m; i++) 
    {
	    int u, v; 
	    cin >> u >> v;
	    adj[u].emplace_back(v); 
	    adj[v].emplace_back(u); 
	}
    
	return 0;
}