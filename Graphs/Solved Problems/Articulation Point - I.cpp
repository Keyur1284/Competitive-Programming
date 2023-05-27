// Problem Link :- https://practice.geeksforgeeks.org/problems/articulation-point-1/1

// Solved by Tarjan's Algorithm
// Time Complexity :- O(E + V)
// Space Complexity :- O(E + V)

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:

    void DFS (int node, int parent, int &clock, vector<int> &insertTime, vector<int> &lowestTime, vector<bool> &vis, vector<bool> &isArticulation, vector<int> adj[])
    {
        vis[node] = true;
        insertTime[node] = lowestTime[node] = clock++;
        int child = 0;

        for (auto &it : adj[node])
        {
            if (it == parent)
                continue;

            if (!vis[it])
            {
                DFS (it, node, clock, insertTime, lowestTime, vis, isArticulation, adj);
                lowestTime[node] = min(lowestTime[node], lowestTime[it]);
                child++;

                if (lowestTime[it] >= insertTime[node] && parent != -1)
                    isArticulation[node] = true;
            }

            else
                lowestTime[node] = min(lowestTime[node], insertTime[it]);
        }

        if (parent == -1 && child > 1)
            isArticulation[node] = true;
    }

    vector<int> articulationPoints(int V, vector<int>adj[]) {

        vector<int> insertTime(V), lowestTime(V);
        vector<bool> vis(V, false), isArticulation(V, false);
        int clock = 0;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                DFS(i, -1, clock, insertTime, lowestTime, vis, isArticulation, adj);
            }
        }

        vector<int> articulationNodes;

        for (int i = 0; i < V; i++)
        {
            if (isArticulation[i])
                articulationNodes.emplace_back(i);
        }

        if(articulationNodes.empty())
            return {-1};

        return articulationNodes;
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
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends