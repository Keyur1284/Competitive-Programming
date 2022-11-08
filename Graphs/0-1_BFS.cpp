#include <bits/stdc++.h>
using namespace std;

vector <int> Shortest_01Bfs (int v, int src, vector <pair<int, int>> adj[])
{
    vector <int> dis(v+1, INT_MAX);
    deque <pair<int, int>> dq;
    dis[src] = 0;
    dq.emplace_front(src, 0);
    
    while(!dq.empty())
    {
        int node = dq.front().first;
        int dist = dq.front().second;
        dq.pop_front();

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int wt = it.second;
            if (dist + wt < dis[adjNode])
            {
                dis[adjNode] = dist + wt;
                
                if (wt == 1)
                    dq.emplace_back(adjNode, dis[adjNode]);

                else
                    dq.emplace_front(adjNode, dis[adjNode]);
            }
        }
    }

    return dis;
}

void addEdge(vector<pair<int, int>> adj[], int u, int v, int wt)
{
    adj[u].emplace_back(v, wt);
    adj[v].emplace_back(u, wt);
}

int main()
{
    //input
    // 6 8
    // 1 2 0
    // 1 3 1
    // 2 3 1
    // 2 4 1
    // 3 5 1
    // 4 5 1
    // 4 6 0
    // 5 6 1

    int v, e;
    cin >> v >> e;

    vector <pair<int, int>> adj[v+1];
    vector <int> dis;

    for(int i = 1; i <= e; i++)
    {
        int a, b, wt;
        cin >> a >> b >> wt;
        addEdge(adj, a, b, wt);
    }

    dis = Shortest_01Bfs(v, 1, adj);

    for (int  i = 1; i<=v; i++)
        cout << dis[i] << " ";

    return 0;
}