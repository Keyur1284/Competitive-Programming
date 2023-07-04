#include <bits/stdc++.h>
using namespace std;
#define ll long long

class SegmentTree {
public:
    
    vector<ll> seg;
    
    // Space Complexity :- O(4 * n)
    
    SegmentTree(ll n)
    {
        seg.resize(4 * n + 1);
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
    
    ll query (ll index, ll left, ll right, ll low, ll high)
    {
        if (right < low || left > high)
            return INT_MAX;
            
        if (left <= low && high <= right)
            return seg[index];
            
        ll mid = (low + high) >> 1;
        ll l = query (2 * index + 1, left, right, low, mid);
        ll r = query (2 * index + 2, left, right, mid + 1, high);
        
        return min(l, r);
    }
    
    // Time Complexity :- O(logn)
    
    void update (ll pos, ll val, ll index, ll low, ll high, vector<ll> &arr)
    {
        if (low == high)
        {
            seg[index] = val;
            return;
        }
        
        ll mid = (low + high) >> 1;
        
        if (pos <= mid)
            update (pos, val, 2 * index + 1, low, mid, arr);
            
        else
            update (pos, val, 2 * index + 2, mid + 1, high, arr);
            
        seg[index] = min(seg[2 * index + 1], seg[2 * index + 2]);
    }
};

int main()
{
    // 6
    // 2 1 0 5 4 3
    
    ll n;
    cin >> n;
    
    vector<ll> arr(n);
    
    for (auto &it : arr)
        cin >> it;
        
    SegmentTree obj(n);
    
    obj.buildTree(0, 0, n - 1, arr);

    for (auto &it : obj.seg)
        cout << it << " ";
        
    cout << endl;
        
    ll q = obj.query(0, 0, 2, 0, n - 1);
    
    cout << q << endl;
    
    obj.update (2, -5, 0, 0, n - 1, arr);
    
    q = obj.query(0, 0, 2, 0, n - 1);
    
    cout << q << endl;
        
    return 0;
}