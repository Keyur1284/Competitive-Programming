//Problem Link :- https://codeforces.com/contest/1722/problem/F

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

ll dx[3] = {-1, 0, 1};
ll dy[3] = {-1, 0, 1};
ll dir[2] = {-1, 1};

void solve()
{
    ll n, m, temp = 1;
    cin >> n >> m;
    
    vector <vector<char>> grid(n, vector<char> (m));
    vvl num(n, vl (m, 0));
    
    F0R (i, n)
    {
        F0R (j, m)
            cin >> grid[i][j];
    }
    
    F0R (i, n)
    {
        F0R (j, m)
        {
            if (grid[i][j] == '*')
            {
                vpl adjh, adjv;
                
                F0R (k, 2)
                {
                    ll x = i + dir[k];
                    ll y = j;
                    
                    if (x >= 0 && x < n && grid[x][y] == '*')
                        adjh.eb(x, y);
                }
                
                F0R (k, 2)
                {
                    ll x = i;
                    ll y = j + dir[k];
                    
                    if (y >= 0 && y < m && grid[x][y] == '*')
                        adjv.eb(x, y);
                }
                
                if (sz(adjh) == 1 && sz(adjv) == 1)
                {
                    if (num[i][j] == 0)
                    {
                        num[i][j] = temp;
                    }
                        
                    else
                    {
                        no;
                        return;
                    }
                    
                    if (num[adjh[0].fi][adjh[0].se] == 0)
                    {
                        num[adjh[0].fi][adjh[0].se] = temp;
                    }
                        
                    else
                    {
                        no;
                        return;
                    }
                    
                    if (num[adjv[0].fi][adjv[0].se] == 0)
                    {
                        num[adjv[0].fi][adjv[0].se] = temp;
                    }
                        
                    else
                    {
                        no;
                        return;
                    }
                                        
                    temp++;
                }
                
                else if (sz(adjh) > 1 || sz(adjv) > 1)
                {
                    no;
                    return;
                }
            }
        }
    }
    
    F0R (i, n)
    {
        F0R (j, m)
        {
            if (grid[i][j] == '*')
            {
                if (num[i][j] == 0)
                {
                    no;
                    return;
                }
                
                F0R (x, 3)
                {
                    F0R (y, 3)
                    {
                        if (i + dx[x] >= 0 && i + dx[x] < n && j + dy[y] >= 0 && j + dy[y] < m && num[i + dx[x]][j + dy[y]] != num[i][j] && num[i + dx[x]][j + dy[y]] != 0)
                        {
                            no;
                            return;
                        }
                    }
                }
            }
        }
    }
    
    yes;
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
    cin >> t;
    
    while (t--)
        solve();
    
	return 0;
}

