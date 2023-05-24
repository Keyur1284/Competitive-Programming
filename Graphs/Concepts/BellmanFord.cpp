// It is used to detect negative cycle in a graph.
// It works only when we are given directed graph.
// In case of undirected graph, convert into a directed graph having edges from a to b and b to a of same edge weights.
// If path-weight < 0, then it is confirmed that the graph has a negative cycle.

// Algorithm :-
// 1. Initialize dist[] = {INF, INF, INF, INF, INF, INF} and dist[source] = 0.
// 2. Relax all edges V - 1 times.
// 3. If dist[u] + wt < dist[v], then dist[v] = dist[u] + wt.
// 4. If dist[u] + wt < dist[v] for any edge after relaxing, then there is a negative cycle in the graph.
// 5. If there is no negative cycle, then dist[] will contain the shortest path from source to all other vertices.


#include <bits/stdc++.h>
using namespace std;
int INF = 1e7;

struct Node
{
    int u;
    int v;
    int wt; 
    
    Node(int first, int second, int weight) 
    {
        u = first;
        v = second;
        wt = weight;
    }
};


int main()
{
    //input
    // 6 7 
    // 3 2 6
    // 5 3 1
    // 0 1 5
    // 1 5 -3
    // 1 2 -2
    // 3 4 -2
    // 2 4 3
    // 0
    
    int n, m;
    cin >> n >> m;

    vector <Node> edges;
    vector <int> dis(n,INF);

    for(int i = 1; i<=m; i++) 
    {
	    int u, v, wt;
	    cin >> u >> v >> wt; 
	    edges.emplace_back(Node(u, v, wt)); 
	}

    int source;
    cin >> source;
    dis[source] = 0;

    for (int i = 1; i<=n-1; i++)
    {
        for (auto it : edges)
        {
            if (dis[it.u] + it.wt < dis[it.v])
                dis[it.v] = dis[it.u] + it.wt;
        }
    }

    int flag = 0; 
    
    for(auto it: edges) 
    {
        if(dis[it.u] + it.wt < dis[it.v]) 
        {
            cout << "Negative cycle is present in the graph"; 
            flag = 1; 
            break; 
        }
    }

    if(!flag) 
    {
        for(int i = 0; i<n; i++) 
            cout << i << " " << dis[i] << endl;
    }


    return 0;
}