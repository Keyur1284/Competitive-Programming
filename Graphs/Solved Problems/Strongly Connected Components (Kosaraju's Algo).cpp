// Problem Link :- https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

// Solved by Kosaraju's Algorithm
// Time Complexity :- O(E + V)
// Space Complexity :- O(E + V)

//This algorithm is for finding the different strongly connected components of the given graph
// Strongly Connected Components (SCC) are only valid for directed graph

// Algorithm:
// 1. Do a DFS traversal of the graph and push the nodes in a stack after visiting all the adjacent nodes
// 2. Reverse the graph
// 3. Pop the nodes from the stack and do a DFS traversal of the graph
// 4. The nodes visited in the DFS traversal are the strongly connected components of the graph

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	void sortingDFS (int node, vector<bool> &vis, stack<int> &st, vector<vector<int>> &adj)
	{
	    vis[node] = true;
	    
	    for (auto &it : adj[node])
	    {
	        if (!vis[it])
	            sortingDFS (it, vis, st, adj);
	    }
	    
	    st.emplace(node);
	}
	
	void sccDFS (int node, vector<bool> &vis, vector<int> revAdj[])
	{
	    vis[node] = true;
	    
	    for (auto &it : revAdj[node])
	    {
	        if (!vis[it])
	            sccDFS (it, vis, revAdj);
	    }
	}
	
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<bool> vis (V, false);
        stack<int> st;
        
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                sortingDFS (i, vis, st, adj);
            }
        }
        
        vector<int> revAdj[V];
        
        for (int i = 0; i < V; i++)
        {
            for (auto &it :adj[i])
            {
                revAdj[it].emplace_back(i);
            }
        }
        
        int SCC = 0;
        vis.assign(V, false);
        
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            
            if (!vis[node])
            {
                sccDFS (node, vis, revAdj);
                SCC++;
            }
        }
        
        return SCC;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends