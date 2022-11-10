/*#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif*/

#include <bits/stdc++.h>
#define ll long long int
#define pi pair <int, int>
#define pl pair <ll, ll>
#define vi vector <int>
#define vpi vector <pi>
#define vpl vector <pl>
#define vl vector <ll>
#define endl '\n'
#define nl cout << '\n' 
#define eb emplace_back
#define em emplace
#define yes cout << "YES" << '\n'
#define no cout << "NO" << '\n'
#define p(x) cout << x << '\n'
#define ps(x) cout << x << " "
#define sz(x) (ll)(x).size()
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define lb(x, key) lower_bound(all(x), key)
#define ub(x, key) upper_bound(all(x), key)
#define rall(x) x.rbegin(), x.rend()
#define F0R(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define RF0R(i, n) for (ll i = n - 1; i >= 0; i--)
#define RFOR(i, a, b) for (ll i = a; i >= b; i--)
#define trav(it, a) for (auto &it : a)
using namespace std;

class DSU 
{
    private:
        vl parent, size, rank;
    
    public:
        DSU (ll n) 
        {
            FOR(i, 0, n) 
            {
                parent.eb(i);
                size.eb(1);
                rank.eb(0);
            }
        }

        ll findPar(ll node)
        {
            if(node == parent[node])
                return node;

            return parent[node] = findPar(parent[node]);
        }
    
        void UnionRank(ll u, ll v)
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

        void UnionSize(ll u, ll v)
        {
            u = findPar(u);
            v = findPar(v);

            if(u == v)
                return;

            else if (size[u] < size[v])
            {
                parent[u] = v;
                size[v] += size[u];
            }

            else if (size[u] >= size[v])
            {
                parent[v] = u;
                size[u] += size[v];
            }
        }
};

ll gcd(ll x, ll y)
{
    if (x == 0)
        return y;
    
    return gcd(y % x, x);
}

void solve()
{
    
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    ll t = 1;
    cin >> t;
    
    while (t--)
        solve();
    
	return 0;
}

