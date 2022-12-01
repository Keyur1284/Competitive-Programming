#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, src;
	cin >> n >> m;
    vector <pair<int,int>> adj[n+1];

    for (int i = 1; i<=m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;

        adj[u].emplace_back(v, wt);
        adj[v].emplace_back(u, wt);
    }

    cin >> src;

    // Dijkstra's algorithm begins from here
    
    priority_queue <pair<int, int> , vector <pair<int, int>>, greater <pair<int, int>>> pq; // min-heap ; In pair => (dist,from)
    vector <int> dis(n+1, INT_MAX);

    pq.emplace(0, src);
    dis[src] = 0;

    while (!pq.empty())
    {
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node])
        {
            if (it.second + distance < dis[it.first])
            {
                dis[it.first] = it.second + distance;
                pq.emplace(dis[it.first], it.first);
            }

        }
    }

    cout << "The distances from source " << src << " are : \n";
    for (auto it : dis)
        (it == INT_MAX)? cout << "INF " : cout << it << " ";

    return 0;
}