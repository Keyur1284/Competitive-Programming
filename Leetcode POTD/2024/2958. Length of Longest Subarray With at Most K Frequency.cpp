// Problem Link :- https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/

// Solved by Sliding Window
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        unordered_map<int, int> freq;
        int n = nums.size(), maxLen = 0;

        for (int start = 0, end = 0; end < n; end++)
        {
            freq[nums[end]]++;

            while (start <= end && freq[nums[end]] > k)
                freq[nums[start++]]--;

            int len = end - start + 1;
            maxLen = max(len, maxLen);
        }

        return maxLen;
    }
};