// Spanning tree :  Whenever we can draw a tree from a given undirected weighted graph such that 
// this tree has all the N nodes and the no. of edges is N - 1 such that every node is reachable from every other node.
// Minimum spanning tree(MST) has minimum sum of edge-weight. 

#include<bits/stdc++.h>
using namespace std;

int main()
{
    //input
    // 6 7
    // 0 1 5
    // 0 2 10
    // 0 3 100
    // 1 3 50
    // 1 4 200
    // 3 4 250
    // 4 5 50

	int n, m;
	cin >> n >> m;
	vector <pair<int,int>> adj[n]; 

	for(int i = 1; i<=m ; i++)
    {
        int a, b, wt;
		cin >> a >> b >> wt;

		adj[a].emplace_back(b, wt);
		adj[b].emplace_back(a, wt);
	}	

    vector <int> key(n, INT_MAX), parent(n);
    vector <bool> mst(n, false);

    key[0] = 0;
    parent[0] = -1;

    for (int count = 1; count <= n - 1; count++)
    {
        int mini = INT_MAX, index;

        for (int v = 0; v <= n - 1; v++)
        {
            if (mst[v] == false && key[v] < mini)
                mini = key[v], index = v;
        }

        mst[index] = true;

        for (auto it : adj[index])
        {
            int ver = it.first;
            int weight = it.second;

            if (mst[ver] == false && weight < key[ver]) 
                parent[ver] = index, key[ver] = weight; 
        }
    }

    for (int i = 1; i <= n - 1; i++) 
        cout << parent[i] << " - " << i <<" \n"; 
    
    return 0;
}
	