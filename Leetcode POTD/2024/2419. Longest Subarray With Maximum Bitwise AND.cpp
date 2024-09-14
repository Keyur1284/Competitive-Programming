// Problem Link :- https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/

// Solved by traversal
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n = nums.size(), maxi = 0, maxLen = 0, len = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > maxi)
            {
                maxi = nums[i];
                len = 1;
                maxLen = 1;
            }

            else if (nums[i] == maxi)
                len++;

            else
                len = 0;

            maxLen = max(len, maxLen);
        }

        return maxLen;
    }
};