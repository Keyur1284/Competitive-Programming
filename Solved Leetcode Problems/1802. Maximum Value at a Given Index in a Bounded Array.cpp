// Problem Link :- https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/

// Solved by Binary Search
// Time Complexity :- O(log(maxSum))
// Space Complexity :- O(1)

class Solution {
public:

    bool check (int mid, int n, int index, int maxSum)
    {
        long long sum = 0;
        
        int left = index + 1, maxLeft = mid;

        if (maxLeft >= left)
            sum += (1LL * left * (maxLeft - left + 1 + maxLeft))/2;     // S_n = n/2 * (a_1 + a_n)

        else
            sum += 1LL * maxLeft * (maxLeft + 1)/2 + left - maxLeft;

        int right = n - left, maxRight = mid - 1;

        if (maxRight >= right)
            sum += (1LL * right * (maxRight - right + 1 + maxRight))/2;

        else
            sum += 1LL * maxRight * (maxRight + 1)/2 + right - maxRight;

        return (sum <= maxSum);
    }

    int maxValue(int n, int index, int maxSum) {
        
        int low = 1, high = maxSum, mid, ans;

        while (low <= high)
        {
            mid = (low + high) >> 1;

            if (check(mid, n, index, maxSum))
            {
                ans = mid;
                low = mid + 1;
            }

            else
                high = mid - 1;
        }

        return ans;
    }
};