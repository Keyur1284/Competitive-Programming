//Problem Link :- https://codeforces.com/contest/1033/problem/A

//  Approach 1 (Using DFS)

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
#define F0R(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define RF0R(i, n) for (ll i = n - 1; i >= 0; i--)
#define RFOR(i, a, b) for (ll i = a; i >= b; i--)
#define trav(it, a) for (auto &it : a)
using namespace std;

ll n, ax, ay, bx, by, cx, cy;
ll dx[3] = {-1, 0, 1};
ll dy[3] = {-1, 0, 1};

void DFS (ll x, ll y, vector<vector<bool>> &vis)
{
    if (x <= 0 || x > n || y <= 0 || y > n || x == ax || y == ay || x + y == ax + ay || x - y == ax - ay)
        return;
        
    vis[x][y] = true;
    
    if (x == cx && y == cy)
    {
        yes;
        exit(0);
    }
    
    F0R(i, 3)
    {
        F0R(j, 3)
        {
            ll newx = x + dx[i];
            ll newy = y + dy[j];
            
            if (!vis[newx][newy])
                DFS (newx, newy, vis);
        }
    }
}

void solve()
{
    cin >> n >> ax >> ay >> bx >> by >> cx >> cy;
    
    vector<vector<bool>> vis(n + 2, vector <bool> (n + 2, false));
    
    DFS (bx, by, vis);
    
    no;
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



//  Approach 2
//  The queen partitions the board into up to four connected components, with each quadrant being one of them. 
//  The answer is thus "YES" if and only if the source king position and the target position are in the same quadrant.

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
#define F0R(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define RF0R(i, n) for (ll i = n - 1; i >= 0; i--)
#define RFOR(i, a, b) for (ll i = a; i >= b; i--)
#define trav(it, a) for (auto &it : a)
using namespace std;

ll quad (ll temp)
{
    return (temp > 0)? 1 : ((temp < 0)? -1 : 0);
}

void solve()
{
    ll n, ax, ay, bx, by, cx, cy;
    cin >> n >> ax >> ay >> bx >> by >> cx >> cy;
    
    bx -= ax, cx -= ax;
    by -= ay, cy -= ay;
    
    if (quad(bx) == quad(cx) && quad(by) == quad(cy))
        yes;
        
    else
        no;
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

