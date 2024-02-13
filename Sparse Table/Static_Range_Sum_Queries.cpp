// Problem Link :- https://cses.fi/problemset/task/1646
// Implementation of Sparse Table for Range Sum Query
// Time Complexity :- O(nlogn) for precomputation, O(1) for query
// Space Complexity :- O(nlogn)

#include <bits/stdc++.h>
using namespace std;
#define int long long

class SparseTable {
private:
    
    vector<vector<int>> st;
    int n, LOG = 0;

public:

    SparseTable(vector<int> &nums) 
    {
        n = nums.size();

        while ((1 << LOG) <= n)
            LOG++;

        st.resize(n, vector<int> (LOG));

        for (int i = 0; i < n; i++)
        {
            st[i][0] = nums[i];
        }

        for (int j = 1; j <= LOG; j++)
        {
            for (int i = 0; i + (1 << j) <= n; i++)
            {
                st[i][j] = st[i][j - 1] + st[i + (1 << (j - 1))][j - 1];
            }
        }
    }

    int query(int l, int r) 
    {
        int sum = 0;

        for (int j = LOG; j >= 0; j--)
        {
            int len = r - l + 1;

            if ((1 << j) <= len)
            {
                sum += st[l][j];
                l += (1 << j);
            }
        }

        return sum;
    }
};

signed main() {
    
    int n, q;
    cin >> n >> q;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) 
    {
        cin >> nums[i];
    }

    SparseTable st(nums);

    while (q--) 
    {
        int l, r;
        cin >> l >> r;
        l--, r--;

        cout << st.query(l, r) << endl;
    }
    
    return 0;
}