#include <bits/stdc++.h>
using namespace std;

int n = 10;
vector <int> parent(n+1), rank(n+1);

void makeSet()
{
    for(int i = 1; i<=n; i++)
        parent[i] = i, rank[i] = 0;
}

int findPar(int node)
{
    if(node == parent[node])
        return node;

    return parent[node] = findPar(parent[node]);
}

void Union(int u, int v)
{
    u = findPar(u);
    v = findPar(v);

    if(rank[u] < rank[v])
        parent[u] = v;

    else if (rank[v] < rank[u])
        parent[v] = u;

    else if (rank[u] == rank[v])
    {
        parent[v] = u;
        rank[u]++;
    }
}

int main()
{
    makeSet();  
    int t;
    cin >> t;

    while(t--)
    {
        int u, v;
        cin >> u >> v;

        Union(u, v);
    }
    return 0;

    //check if two nodes belong to same components or different components
    if (findPar(num1) != findPar(num2))
        cout << "Different" << endl;

    else
        cout << "Same" << endl;
}

    