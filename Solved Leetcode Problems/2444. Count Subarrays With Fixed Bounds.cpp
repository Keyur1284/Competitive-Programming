// Problem Link :- https://leetcode.com/problems/count-subarrays-with-fixed-bounds/

// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {

        long long maxPos = -1, minPos = -1, outRange = -1, ans = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > maxK || nums[i] < minK)
                outRange = i;

            if (nums[i] == minK)
                minPos = i;

            if (nums[i] == maxK)
                maxPos = i;

            long long temp = min(minPos, maxPos) - outRange;

            ans += max(0LL, temp);
        }

        return ans; 
    }
};
