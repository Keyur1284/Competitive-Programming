// Problem Link :- https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

// Solved by Binary Search
// Time Complexity :- O(nlog(maxElement))
// Space Complexity :- O(1)

class Solution {
public:

    bool check (int mid, vector<int>& nums, int threshold)
    {
        int sum = 0;

        for (auto &it : nums)
        {
            sum += (it + mid - 1)/mid;

            if (sum > threshold)
                return false;
        }

        return true;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int low = 1, high = *max_element(nums.begin(), nums.end()), mid, ans;

        while (low <= high)
        {
            mid = (low + high) >> 1;

            if (check(mid, nums, threshold))
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