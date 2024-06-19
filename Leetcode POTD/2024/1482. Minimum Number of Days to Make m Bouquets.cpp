// Problem Link :- https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

// Solved by Binary Search
// Time Complexity :- O(n * log(maxDays - minDays))
// Space Complexity :- O(1)

class Solution {
public:

    bool check (int mid, int n, vector<int>& bloomDay, int m, int k)
    {
        int bouquets = 0, cons = 0;

        for (int i = 0; i < n; i++)
        {
            if (bloomDay[i] <= mid)
                cons++;

            else
                cons = 0;

            if (cons == k)
            {
                bouquets++;
                cons = 0;
            }

            if (bouquets == m)
                return true;
        }

        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int n = bloomDay.size();

        if (1LL * n < 1LL * m * k)
            return -1;

        auto bounds = minmax_element(bloomDay.begin(), bloomDay.end());

        int low = *bounds.first, high = *bounds.second, mid, ans = -1;

        while (low <= high)
        {
            mid = (low + high) >> 1;

            if (check(mid, n, bloomDay, m, k))
            {
                ans = mid;
                high = mid - 1;
            }

            else
                low = mid + 1;
        }

        return ans;
    }
};