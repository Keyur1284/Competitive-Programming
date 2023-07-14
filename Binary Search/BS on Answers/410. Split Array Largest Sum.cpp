// Problem Link :- https://leetcode.com/problems/split-array-largest-sum/

// Solved by Binary Search  (Same as Allocate minimum number of pages problem)
// Time Complexity :- O(n * log(sum - max))
// Space Complexity :- O(1)

class Solution {
public:

    bool check (int mid, vector<int>& nums, int k)
    {
        int count = 1, sum = 0;

        for (auto &it : nums)
        {
            if (it > mid)
                return false;

            if (sum + it > mid)
            {
                count++;
                sum = it;
            }

            else
                sum += it;

            if (count > k)
                return false;
        }

        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int mid, ans;

        while (low <= high)
        {
            mid = (low + high) >> 1;

            if (check(mid, nums, k))
                high = mid - 1;

            else
                low = mid + 1;
        }

        return low;
    }
};