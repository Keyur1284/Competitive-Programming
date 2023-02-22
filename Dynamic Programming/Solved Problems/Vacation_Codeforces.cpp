//Problem Link :- https://codeforces.com/contest/698/problem/A

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define ll long long int
#define ld long double
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
#define imx INT_MAX
#define imn INT_MIN
#define lmx LLONG_MAX
#define lmn LLONG_MIN
#define pi pair <int, int>
#define pl pair <ll, ll>
#define vi vector <int>
#define vvi vector <vector<int>>    
#define vvvi vector <vector<vector<int>>>
#define vpi vector <pi>
#define vpl vector <pl>
#define vl vector <ll>
#define vvl vector <vector<ll>>    
#define vvvl vector <vector<vector<ll>>>  
#define minpq priority_queue <ll, vector<ll>, greater<ll>>
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
#define initialize(a, i) memset(a, i, sizeof(a))
#define F0R(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define RF0R(i, n) for (ll i = n - 1; i >= 0; i--)
#define RFOR(i, a, b) for (ll i = a; i >= b; i--)
#define trav(it, a) for (auto &it : a)
using namespace std;

ll func (ll index, ll gym, ll cont, vl &points, vvvl &dp)
{
    if (index >= sz(points))
        return 0;
        
    if (dp[index][gym][cont] != -1)
        return dp[index][gym][cont];
        
    dp[index][gym][cont] = 1 + func(index + 1, 0, 0, points, dp);
    
    if (points[index] == 1 && cont == 0)
    {
        dp[index][gym][cont] = min (dp[index][gym][cont], func(index + 1, 0, 1, points, dp));
    }
    
    if (points[index] == 2 && gym == 0)
    {
        dp[index][gym][cont] = min (dp[index][gym][cont], func(index + 1, 1, 0, points, dp));
    }
    
    if (points[index] == 3)
    {
        if (gym == 0)
        {
            dp[index][gym][cont] = min (dp[index][gym][cont], func(index + 1, 1, 0, points, dp));
        }
        
        if (cont == 0)
        {
            dp[index][gym][cont] = min (dp[index][gym][cont], func(index + 1, 0, 1, points, dp));
        }
    }
    
    return dp[index][gym][cont];
}

void solve()
{
    ll n;
    cin >> n;
    
    vvvl dp(n + 1, vvl (2, vl (2, -1)));
    vl points(n);
    
    F0R (i, n)
    {
        cin >> points[i];
    }
        
    p(func(0, 0, 0, points, dp));    
}

signed main() 
{
    // #ifndef ONLINE_JUDGE
    // // for getting input from input.txt
    // freopen("input.txt", "r", stdin);
    // // for writing output to output.txt
    // freopen("output.txt", "w", stdout);
    // #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    ll t = 1;
    // cin >> t;
    
    while (t--)
        solve();
    
	return 0;
}
