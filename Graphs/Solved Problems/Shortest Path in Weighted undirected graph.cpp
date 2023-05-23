// Problem Link :- https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1

// Time Complexity :- O(ElogV)      E = no. of edges, V = no. of vertices
// Space Complexity :- O(E + V)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:

    void findPar (int node, vector<int> &path, vector<int> &parent)
    {
        if (node == parent[node])
        {
            path.emplace_back(node);
            return;
        }

        findPar(parent[node], path, parent);
        path.emplace_back(node);
    }

    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {

        vector<pair<int, int>> adj[n + 1];

        for (auto &it : edges)
        {
            adj[it[0]].emplace_back(it[1], it[2]);
            adj[it[1]].emplace_back(it[0], it[2]);
        }

        vector<int> dist(n + 1, INT_MAX), parent(n + 1);
        iota (parent.begin(), parent.end(), 0);



        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[1] = 0;
        pq.emplace(0, 1);

        while (!pq.empty())
        {
            int node = pq.top().second;
            int steps = pq.top().first;
            pq.pop();

            for (auto &it : adj[node])
            {
                if (steps + it.second < dist[it.first])
                {
                    dist[it.first] = steps + it.second;
                    parent[it.first] = node;

                    pq.emplace(dist[it.first], it.first);
                }
            }
        }

        if (dist[n] == INT_MAX)
            return {-1};

        vector<int> path;

        findPar (n, path, parent);

        return path;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends