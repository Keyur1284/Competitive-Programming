#include<bits/stdc++.h>
using namespace std;

struct Node {
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

bool comp(Node a, Node b)
{
    return a.wt < b.wt;
}

int findPar(int ver, vector<int> &parent) 
{
    if(ver == parent[ver]) 
        return ver; 

    return parent[ver] = findPar(parent[ver], parent); 
}

void Union (int u, int v, vector<int> &parent, vector<int> &rank) 
{
    u = findPar(u, parent);
    v = findPar(v, parent);
    
    if (rank[u] < rank[v])
    	parent[u] = v;

    else if (rank[v] < rank[u])
    	parent[v] = u; 
    
    else if (rank[v] == rank[u])
    {
    	parent[v] = u;
    	rank[u]++; 
    }
}

int main()
{
	//input
	// 6 9
	// 5 4 9
	// 5 1 4
	// 4 3 5
	// 4 2 3
	// 4 1 1
	// 1 2 2
	// 3 2 3
	// 3 6 8
	// 2 6 7
	
	int n, m;
	cin >> n >> m;
	vector<Node> edges; 

	for(int i = 1; i<=m; i++) 
    {
	    int u, v, wt;
	    cin >> u >> v >> wt; 
	    edges.emplace_back(Node(u, v, wt)); 
	}

	sort(edges.begin(), edges.end(), comp); 
	
	vector<int> parent(n+1), rank(n+1, 0);
	
    for(int i = 1; i<=n; i++) 
	    parent[i] = i; 
	
	int cost = 0;
	vector<pair<int,int>> mst; 

	for(auto it : edges) 
    {
	    if(findPar(it.v, parent) != findPar(it.u, parent)) 
        {
	        cost += it.wt; 
	        mst.emplace_back(it.u, it.v); 
	        Union(it.u, it.v, parent, rank); 
	    }
	}

	cout << "Weight of MST = " << cost << endl;

	for(auto it : mst) 
        cout << it.first << " - " << it.second << endl; 

	return 0;
}