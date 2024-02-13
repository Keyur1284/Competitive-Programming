// Problem Link :- https://cses.fi/problemset/task/1648
// Solved using Fenwick Tree (Binary Indexed Tree)
// Time Complexity :- O(nlogn) for building the BIT and O(logn) for each query and update operation
// Space Complexity :- O(n)
 
#include <bits/stdc++.h>
using namespace std;
#define int long long

class BIT {

    int n;
    vector<int> bit;

public:

    BIT (int n)
    {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void update (int id, int val)
    {
        while (id <= n)
        {
            bit[id] += val;
            id += (id & -id);
        }
    }

    int query (int id)
    {
        int sum = 0;

        while (id > 0)
        {
            sum += bit[id];
            id -= (id & -id);
        }

        return sum;
    }
};

signed main()
{
    int n, q;
    cin >> n >> q;

    vector<int> nums(n + 1);
    BIT bit(n);

    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
        bit.update(i, nums[i]);
    }

    while (q--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int k, u;
            cin >> k >> u;

            bit.update(k, -nums[k]);
            nums[k] = u;
            bit.update(k, nums[k]);
        }

        else
        {
            int l, r;
            cin >> l >> r;

            int leftSum = bit.query(l - 1), rightSum = bit.query(r);
            int rangeSum = rightSum - leftSum;

            cout << rangeSum << endl;
        }
    }

    return 0;
}