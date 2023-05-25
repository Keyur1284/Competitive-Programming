// Problem Link :- https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

// Spanning tree :  Whenever we can draw a tree from a given undirected weighted graph such that 
// this tree has all the N nodes and the no. of edges is N - 1 such that every node is reachable from every other node.
// Minimum spanning tree(MST) has minimum sum of edge-weight. 

// Solved by Prim's Algorithm
// Time Complexity :- O(ElogV)
// Space Complexity :- O(E + V)

// Algorithm :-
// 1. Create a vector vis that keeps track of vertices already included in MST.
// 2. Create a vector key that keeps track of key value of vertices. Initialize all key values as INFINITE.
// 3. Create a vector parent that keeps track of parent of vertices. Initialize all parent values as -1.
// 4. Include first vertex in MST by setting key value as 0.
// 5. While vis doesn't include all vertices :-
//    a. Pick a vertex u which is not in vis and has minimum key value.
//    b. Include u to vis.
//    c. Update key value of all adjacent vertices of u. To update the key values, iterate through all adjacent vertices.
//       For every adjacent vertex v, if weight of edge u-v is less than the previous key value of v, update the key value as weight of u-v.
//       Also, update parent value of v as u.


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



// Solved by Kruskal's Algorithm
// Time Complexity :- O(ElogE + ElogV)
// Space Complexity :- O(E + V)

// Algorithm :-
// 1. Sort all the edges in non-decreasing order of their weight.
// 2. Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far.
//    If cycle is not formed, include this edge. Else, discard it.
// 3. Repeat step#2 until there are (V-1) edges in the spanning tree.


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DSU {

private:
    
    vector<int> parent, rank, size;

public:

    DSU (int n)
    {
        for (int i = 0; i <= n; i++)
        {
            parent.emplace_back(i);
            rank.emplace_back(0);
            size.emplace_back(1);
        }
    }

    int findPar (int node)
    {
        if (node == parent[node])
            return node;

        return parent[node] = findPar(parent[node]);
    }

    void UnionRank (int u, int v)
    {
        u = findPar(u);
        v = findPar(v);

        if (u == v)
            return;

        if (rank[u] < rank[v])
        {
            parent[u] = v;
        }

        else if (rank[u] > rank[v])
        {
            parent[v] = u;
        }

        else if (rank[u] == rank[v])
        {
            parent[v] = u;
            rank[u]++;
        }
    }

    void UnionSize (int u, int v)
    {
        u = findPar(u);
        v = findPar(v);

        if (u == v)
            return;

        if (size[u] < size[v])
        {
            parent[u] = v;
            size[v] += size[u];
        }

        else if (rank[u] >= rank[v])
        {
            parent[v] = u;
            size[u] += size[v];
        }
    }    
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        DSU dsu(V - 1);
        
        vector<vector<int>> edges;
        
        for (int node = 0; node < V; node++)
        {
            for (auto &it : adj[node])
            {
                edges.push_back({it[1], node, it[0]});
            }
        }
        
        sort (edges.begin(), edges.end());
        int sum = 0;
        
        for (auto &it : edges)
        {
            if (dsu.findPar(it[1]) != dsu.findPar(it[2]))
            {
                sum += it[0];
                dsu.UnionSize(it[1], it[2]);
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