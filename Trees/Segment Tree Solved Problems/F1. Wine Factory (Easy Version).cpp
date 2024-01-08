#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define ll long long
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
#define db(x) debug(x)
using namespace std;
using namespace __gnu_pbds; 
template <class T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define debug(...) 8
#endif

class Node {
public:

    ll wine, canGive, canTake;

    Node ()
    {
        wine = canGive = canTake = 0;
    }

    Node (ll water, ll power)
    {
        wine = min(water, power);
        canGive = water - wine;
        canTake = power - wine;
    }

    void merge (Node &left, Node &right)
    {
        ll moreWine = min(left.canGive, right.canTake);
        wine = left.wine + right.wine + moreWine;
        canGive = left.canGive + right.canGive - moreWine;
        canTake = left.canTake + right.canTake - moreWine;    
    }
};

class SegmentTree {
public:
    
    vector<Node> seg;
        
    SegmentTree(ll n)
    {
        seg.resize(4 * n + 1);
    }
        
    void buildTree (ll index, ll low, ll high, vpl &arr)
    {
        if (low == high)
        {
            seg[index] = Node(arr[low].fi, arr[low].se);
            return;
        }
        
        ll mid = (low + high) >> 1;
        buildTree (2 * index + 1, low, mid, arr);
        buildTree (2 * index + 2, mid + 1, high, arr);
        
        seg[index].merge(seg[2 * index + 1], seg[2 * index + 2]);
    }
        
    Node query (ll left, ll right, ll index, ll low, ll high)
    {
        if (right < low || left > high)
            return Node(0, 0);
            
        if (left <= low && high <= right)
            return seg[index];
            
        ll mid = (low + high) >> 1;
        Node l = query (left, right, 2 * index + 1, low, mid);
        Node r = query (left, right, 2 * index + 2, mid + 1, high);
        
        Node ans = Node(0, 0);
        ans.merge(l, r);
        
        return ans;
    }
        
    void update (ll pos, ll water, ll power, ll index, ll low, ll high)
    {
        if (low == high)
        {
            seg[index] = Node(water, power);
            return;
        }
        
        ll mid = (low + high) >> 1;
        
        if (pos <= mid)
            update (pos, water, power, 2 * index + 1, low, mid);
            
        else
            update (pos, water, power, 2 * index + 2, mid + 1, high);
            
        seg[index].merge(seg[2 * index + 1], seg[2 * index + 2]);
    }
};

void solve()
{
    ll n, q;
    cin >> n >> q;

    vpl arr(n);

    F0R (i, n)
        cin >> arr[i].fi;

    F0R (i, n)
        cin >> arr[i].se;

    ll c;
    
    F0R (i, n - 1)
        cin >> c;

    SegmentTree st(n);
    st.buildTree(0, 0, n - 1, arr);

    while (q--)
    {
        ll p, x, y, z;
        cin >> p >> x >> y >> z;

        st.update(p - 1, x, y, 0, 0, n - 1);
        ll ans = st.query(0, n - 1, 0, 0, n - 1).wine;

        p(ans);
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