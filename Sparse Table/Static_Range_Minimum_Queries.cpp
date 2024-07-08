// Problem Link :- https://cses.fi/problemset/task/1647
// Implementing Sparse Table for Range Minimum Query
// Time Complexity :- O(nlogn) for precomputation, O(1) for query
// Space Complexity :- O(nlogn)

#include <bits/stdc++.h>
using namespace std;

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

        st.resize(n, vector<int> (LOG + 1));

        for (int i = 0; i < n; i++)
        {
            st[i][0] = nums[i];
        }

        for (int j = 1; j <= LOG; j++)
        {
            for (int i = 0; i + (1 << j) - 1 < n; i++)
            {
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query(int l, int r) 
    {
        int len = r - l + 1;
        // int j = log2(len);
        int j = 31 - __builtin_clz(len);
        return min(st[l][j], st[r - (1 << j) + 1][j]);
    }
};

int main() {
    
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
