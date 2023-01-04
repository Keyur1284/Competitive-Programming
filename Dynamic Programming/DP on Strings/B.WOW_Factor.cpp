//Problem Link :- https://codeforces.com/contest/1178/problem/B

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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
#define F0R(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define RF0R(i, n) for (ll i = n - 1; i >= 0; i--)
#define RFOR(i, a, b) for (ll i = a; i >= b; i--)
#define trav(it, a) for (auto &it : a)
using namespace std;

void solve()
{
    string s;
    cin >> s;
    
    ll n = sz(s), ans = 0;
    
    vl pref(n, 0), suff(n, 0);
    
    FOR (i, 1, n - 1)
    {
        if (s[i] == 'v' && s[i - 1] == 'v')
            pref[i]++;
            
        pref[i] += pref[i - 1];
    }
    
    RFOR (i, n - 2, 0)
    {
        if (s[i] == 'v' && s[i + 1] == 'v')
            suff[i]++;
            
        suff[i] += suff[i + 1];
    }
    
    FOR (i, 2, n - 3)
    {
        if (s[i] == 'o')
            ans += pref[i - 1] * suff[i + 1];    
    }
    
    p(ans);
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
    //cin >> t;
    
    while (t--)
        solve();
    
	return 0;
}

