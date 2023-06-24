// Problem Link :- https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

// Solved by Binary Search
// Time Complexity :- O(nlog(maxSum))
// Space Complexity :- O(1)

class Solution {
public:

    bool check (long long mid, vector<int>& weights, int days)
    {
        int day = 1, weight = 0;

        for (auto &it : weights)
        {
            if (it > mid)
                return false;

            if (it + weight > mid)
            {
                day++;
                weight = it;
            }

            else
                weight += it;

            if (day > days)
                return false;
        }

        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        
        long long low = *max_element(weights.begin(), weights.end());
        long long high = accumulate(weights.begin(), weights.end(), 0LL);
        long long mid, ans = high;

        while (low <= high)
        {
            mid = (low + high) >> 1;

            if (check(mid, weights, days))
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