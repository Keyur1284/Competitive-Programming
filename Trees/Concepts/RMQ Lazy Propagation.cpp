#include <bits/stdc++.h>
using namespace std;
#define ll long long

class SegmentTree {
public:
    
    vector<ll> seg, lazy;
    
    // Space Complexity :- O(4 * n)
    
    SegmentTree(ll n)
    {
        seg.resize(4 * n + 1);
        lazy.resize(4 * n + 1);
    }
    
    // Time Complexity :- O(n)
    
    void buildTree (ll index, ll low, ll high, vector<ll> &arr)
    {
        if (low == high)
        {
            seg[index] = arr[low];
            return;
        }
        
        ll mid = (low + high) >> 1;
        buildTree (2 * index + 1, low, mid, arr);
        buildTree (2 * index + 2, mid + 1, high, arr);
        
        seg[index] = min(seg[2 * index + 1], seg[2 * index + 2]);
    }
    
    // Time Complexity :- O(logn)
    
    ll query (ll left, ll right, ll index, ll low, ll high)
    {
        if (lazy[index] != 0)
        {
            seg[index] += lazy[index];
            
            if (low != high)
            {
                lazy[2 * index + 1] += lazy[index];
                lazy[2 * index + 2] += lazy[index];
            }
            
            lazy[index] = 0;
        }
        
        if (right < low || left > high)
            return INT_MAX;
            
        if (left <= low && high <= right)
            return seg[index];
            
        ll mid = (low + high) >> 1;
        ll l = query (left, right, 2 * index + 1, low, mid);
        ll r = query (left, right, 2 * index + 2, mid + 1, high);
        
        return min(l, r);
    }
    
    // Time Complexity :- O(logn)
    
    void update (ll left, ll right, ll val, ll index, ll low, ll high)
    {
        if (lazy[index] != 0)
        {
            seg[index] += lazy[index];
            
            if (low != high)
            {
                lazy[2 * index + 1] += lazy[index];
                lazy[2 * index + 2] += lazy[index];
            }
            
            lazy[index] = 0;
        }
        
        if (high < left || low > right)
            return;
            
        if (left <= low && high <= right)
        {
            seg[index] += val;
            
            if (low != high)
            {
                lazy[2 * index + 1] += val;
                lazy[2 * index + 2] += val;
            }
            
            return;
        }
        
        ll mid = (low + high) >> 1;
        update (left, right, val, 2 * index + 1, low, mid);
        update (left, right, val, 2 * index + 2, mid + 1, high);
            
        seg[index] = min(seg[2 * index + 1], seg[2 * index + 2]);
    }
};

int main()
{
    ll n;
    cin >> n;
    
    vector<ll> arr(n);
    
    for (auto &it : arr)
        cin >> it;
        
    SegmentTree st(n);
    
    st.buildTree(0, 0, n - 1, arr);

    ll q;
    cin >> q;
    
    while (q--)
    {
        ll type;
        cin >> type;
        
        if (type == 1)
        {
            ll l, r;
            cin >> l >> r;
            
            ll sum = st.query (l, r, 0, 0, n - 1);
            cout << sum << endl;
        }
        
        else if (type == 2)
        {
            ll l, r, val;
            cin >> l >> r >> val;
            
            st.update (l, r, val, 0, 0, n - 1);
        }
    }
        
    return 0;
}