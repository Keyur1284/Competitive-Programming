/*#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif*/

#include <bits/stdc++.h>
#define ll long long int
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
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ins insert
#define F0R(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define RF0R(i, n) for (ll i = n - 1; i >= 0; i--)
#define RFOR(i, a, b) for (ll i = a; i >= b; i--)
#define trav(it, a) for (auto &it : a)
using namespace std;

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

