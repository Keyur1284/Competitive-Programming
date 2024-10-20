//Problem Link :- https://atcoder.jp/contests/dp/tasks/dp_b

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

void solve()
{
    ll n, k;
    cin >> n >> k;
    
    vl heights(n), dp(n);
    dp[0] = 0;
    
    trav(it, heights)
        cin >> it;
        
    FOR (i, 1, n - 1)
    {
        ll steps = INT_MAX;
        
        FOR (j, 1, k)
        {
            if (i - j >= 0)
            {
                ll jump = dp[i - j] + abs (heights[i - j] - heights[i]);
                steps = min (steps, jump);
            }
        }
        
        dp[i] = steps;
    }
    
    p(dp[n-1]);
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    ll t = 1;
    //cin >> t;
    
    while (t--)
        solve();
    
	return 0;
}

