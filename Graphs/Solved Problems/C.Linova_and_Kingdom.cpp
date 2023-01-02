//Problem Link :- https://codeforces.com/contest/1337/problem/C

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long int
#define ld long double
const ll MOD = 1e9 + 7;
#define imx INT_MAX
#define imn INT_MIN
#define lmx LLONG_MAX
#define lmn LLONG_MIN
#define pi pair <int, int>
#define pl pair <ll, ll>
#define vi vector <int>
#define vvi vector<vector<int>>    
#define vvvi vector<vector<vector<int>>>
#define vpi vector <pi>
#define vpl vector <pl>
#define vl vector <ll>
#define vvl vector<vector<ll>>    
#define vvvl vector<vector<vector<ll>>>  
#define endl '\n'
#define nl cout << '\n' 
#define pb push_back
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

ll DFS (ll node, ll parent, vl &depth, vl &size, ll happiness[], vl &vis, vl adj[])
{
    depth[node] = depth[parent] + 1;
    size[node] = 1;
    vis[node] = 1;
    
    trav (it, adj[node])
    {
        if (it != parent && !vis[it])
            size[node] += DFS (it, node, depth, size, happiness, vis, adj);
    }
    
    happiness[node] = size[node] - depth[node];
    
    return size[node];
}

void solve()
{
    ll n, k, ans = 0;
    cin >> n >> k;
    
    ll happiness[n + 1]{0};
    vl adj[n + 1], depth(n + 1, 0), size(n + 1, 0), vis(n + 1, 0);
    
    vis[0] = 1;
    
    F0R(i, n - 1)
    {
        ll u, v;
        cin >> u >> v;
        
        adj[u].eb(v);
        adj[v].eb(u);
    }
    
    DFS (1, 0, depth, size, happiness, vis, adj);
    
    nth_element (happiness + 1, happiness + n - k, happiness + n + 1, greater<ll>());
    
    FOR (i, 1, n - k)
        ans += happiness[i];
        
    p(ans);
}

signed main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    ll t = 1;
    //cin >> t;
    
    while (t--)
        solve();
    
	return 0;
}

