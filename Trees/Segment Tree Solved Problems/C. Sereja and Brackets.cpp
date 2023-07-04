// Problem Link :- https://codeforces.com/contest/380/problem/C

// Solved by Segment Tree
// Time Complexity :- O(len + qlog(len))
// Space Complexity :- O(len)

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

struct Node {

        int open, close, full;

        Node (int a, int b, int c)
        {
            open = a;
            close = b;
            full = c;
        }

    };

class SegmentTree {
public:
  
    vector<Node> seg;
        
    SegmentTree(ll n)
    {
        seg.assign(4 * n + 1, Node(0, 0, 0));
    }

    Node merge (Node left, Node right)
    {
        Node ans = Node(0, 0, 0);

        ll correct = min(left.open, right.close);
        ans.full = correct + left.full + right.full;
        ans.open = left.open - correct + right.open;
        ans.close = left.close + right.close - correct;

        return ans;
    }
        
    void buildTree (ll index, ll low, ll high, string &s)
    {
        if (low == high)
        {
            if (s[low] == '(')
                seg[index].open++;

            else
                seg[index].close++;
            
            return;
        }
        
        ll mid = (low + high) >> 1;
        buildTree (2 * index + 1, low, mid, s);
        buildTree (2 * index + 2, mid + 1, high, s);

        seg[index] = merge(seg[2 * index + 1], seg[2 * index + 2]);
    }
        
    Node query (ll index, ll left, ll right, ll low, ll high) 
    {
        if (right < low || left > high)
            return Node(0, 0, 0);
            
        if (left <= low && high <= right)
            return seg[index];
            
        ll mid = (low + high) >> 1;
        Node l = query (2 * index + 1, left, right, low, mid);
        Node r = query (2 * index + 2, left, right, mid + 1, high);

        Node ans = merge(l, r);
        return ans;
    }
};

void solve()
{
    string s;
    cin >> s;

    ll n = sz(s);

    SegmentTree st(n);

    st.buildTree(0, 0, n - 1, s);

    ll m;
    cin >> m;

    while (m--)
    {
        ll l, r;
        cin >> l >> r;
        l--, r--;

        Node ans = st.query(0, l, r, 0, n - 1);

        p(2 * (ans.full));
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