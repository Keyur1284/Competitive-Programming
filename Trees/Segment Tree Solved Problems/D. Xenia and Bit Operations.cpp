// Problem Link :- https://codeforces.com/contest/339/problem/D

// Solved by Segment Tree
// Time Complexity :- O(2 ^ n + qlog(2 ^ n))
// Space Complexity :- O(2^n)

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

class SegmentTree {
public:
    
    vector<ll> seg;
    
    SegmentTree(ll n)
    {
        seg.resize(4 * n + 1);
    }
    
    void buildTree (ll index, ll low, ll high, vector<ll> &arr, bool isOr)
    {
        if (low == high)
        {
            seg[index] = arr[low];
            return;
        }
        
        ll mid = (low + high) >> 1;
        buildTree (2 * index + 1, low, mid, arr, !isOr);
        buildTree (2 * index + 2, mid + 1, high, arr, !isOr);
        
        if (isOr)
            seg[index] = seg[2 * index + 1] | seg[2 * index + 2];

        else
            seg[index] = seg[2 * index + 1] ^ seg[2 * index + 2];
    }
    
    void update (ll pos, ll val, ll index, ll low, ll high, vector<ll> &arr, bool isOr)
    {
        if (low == high)
        {
            seg[index] = val;
            return;
        }
        
        ll mid = (low + high) >> 1;
        
        if (pos <= mid)
            update (pos, val, 2 * index + 1, low, mid, arr, !isOr);
            
        else
            update (pos, val, 2 * index + 2, mid + 1, high, arr, !isOr);

        if (isOr)    
            seg[index] = seg[2 * index + 1] | seg[2 * index + 2];

        else
            seg[index] = seg[2 * index + 1] ^ seg[2 * index + 2];
    }
};

void solve()
{
    ll n, q;
    cin >> n >> q;

    ll size = (1 << n);

    vl arr(size);

    trav (it, arr)
        cin >> it;

    SegmentTree st(size);

    bool isOr = (n & 1);

    st.buildTree(0, 0, size - 1, arr, isOr);

    while (q--)
    {
        ll pos, val;
        cin >> pos >> val;
        pos--;

        st.update(pos, val, 0, 0, size - 1, arr, isOr);

        cout << st.seg[0] << endl;
    }
}

signed main() 
{
    // #ifndef ONLINE_JUDGE
    // // for getting input from input.txt
    // freopen("input.txt", "r", stdin);
    // // for writing output to output.txt
    // freopen("output.txt", "w", stdout);
    // #endif

    // clock_t begin = clock();
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t = 1;
    // cin >> t;

    while (t--)
        solve();
        
    // printf("%.3lf seconds\n", (double) (clock() - begin) / CLOCKS_PER_SEC);
    
	return 0;
}