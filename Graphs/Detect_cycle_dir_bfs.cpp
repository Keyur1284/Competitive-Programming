//Topological sort is valid only for directed acyclic graphs
//Defination : Linear ordering of vertices such that if there is an edge u -> v then u appears before v in that ordering

//Topological done by bfs is also known as Kahn's Algorithm

#include <bits/stdc++.h>
using namespace std;
int flag = 0;

bool isCyclic(int v, vector <int> adj[])
{
    queue <int> q;
    vector <int> indegree(v+1, 0);

    for(int i = 1; i<=v; i++) 
    {
        for(auto it : adj[i]) 
            indegree[it]++; 
	}
	    
	for(int i = 1; i<=v; i++) 
    {        
        if(indegree[i] == 0) 
            q.emplace(i);  
	}

    int count = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        count++;

        for (auto it : adj[node])
        {
            indegree[it]--;

            if (indegree[it] == 0)
                q.emplace(it);
        }
    }

    if (count != v)
        return true;

    else
        return false;
}

int main()
{
    int v, e;
    cin >> v >> e;

    vector<int> adj[v+1];

    for(int i = 1; i <= e; i++)
    {
        int src, dest;
        cin >> src >> dest;
        adj[src].emplace_back(dest);
    }


    if(isCyclic(v, adj))
        cout << "YES" << endl;

    else
        cout << "NO" << endl;
   
    return 0;
}
