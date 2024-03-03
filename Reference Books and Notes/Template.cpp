/*#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif*/

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
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
using namespace __gnu_pbds; 
template <class T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template <class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key (k) : Number of items strictly smaller than k
// find_by_order(k) : K-th element in a set (counting from 0)

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

            if (u == v)
                return;

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

bool is_prime (ll num)
{
    if (num == 2 || num == 3)
        return true;
        
    for (ll i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }
    
    return true;
}

const ll N = 2e5+5;
vl fact(N);

ll mod_power(ll num, ll p) 
{
    ll res = 1;
    
    // while (p) 
    // {
    //     if (p % 2)
    //         res = (((res % MOD) * (num % MOD)) % MOD), p--;
    //     else
    //         num = (((num % MOD) * (num % MOD)) % MOD), p /= 2;
    // }

    while (p)
    {
        if (p % 2)
            res = (((res % MOD) * (num % MOD)) % MOD);

        p /= 2;
        num = (((num % MOD) * (num % MOD)) % MOD);
    }
    
    
    return res;
}

ll inverse(ll num) 
{ 
    return mod_power(num, MOD - 2); 
}

void pre() 
{
    fact[0] = fact[1] = 1;
    
    FOR(i, 2, N - 1) 
    {
        fact[i] = (fact[i-1] * 1LL * i) % MOD;
    }
}

ll nCr(ll n, ll r) 
{
    if (r > n)
        return 0;
    
    ll res = fact[n];
    res = (res * 1LL * inverse(fact[r])) % MOD;
    res = (res * 1LL * inverse(fact[n - r])) % MOD;
    
    return res;
}

ll nPr(ll n, ll r) 
{
    if (r > n)
        return 0;
    
    ll res = fact[n];
    res = (res * 1LL * inverse(fact[n - r])) % MOD;
    
    return res;
}

int log_a_to_base_b(int a, int b)
{
    return (a > b - 1) ? 1 + log_a_to_base_b(a / b, b) : 0;
}

void solve()
{
    
}

signed main() 
{
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    clock_t begin = clock();

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    ll t = 1;
    cin >> t;
    
    while (t--)
        solve();
    
    printf("%.3lf seconds\n", (double) (clock() - begin) / CLOCKS_PER_SEC);


	return 0;
}
