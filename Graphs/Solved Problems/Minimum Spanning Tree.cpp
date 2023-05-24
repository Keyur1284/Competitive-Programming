// Problem Link :- https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

// Spanning tree :  Whenever we can draw a tree from a given undirected weighted graph such that 
// this tree has all the N nodes and the no. of edges is N - 1 such that every node is reachable from every other node.
// Minimum spanning tree(MST) has minimum sum of edge-weight. 

// Solved by Prim's Algorithm
// Time Complexity :- O(ElogV)
// Space Complexity :- O(E + V)

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int sum = 0;
        vector<bool> vis(V, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.emplace(0, 0);

        while (!pq.empty())
        {
            auto vertex = pq.top();
            int node = vertex.second;
            int wt = vertex.first;
            pq.pop();

            if (!vis[node])
            {
                vis[node] = true;
                sum += wt;

                for (auto &it : adj[node])
                {
                    if (!vis[it[0]])
                    {
                        pq.emplace(it[1], it[0]);
                    }
                }
            }
        }

        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends