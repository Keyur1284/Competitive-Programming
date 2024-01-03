// Problem Link :- https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

// Solved by Sliding Window
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n = nums.size(), maxLen = 0, zeroes = 0;

        for (int start = 0, end = 0; end < n; end++)
        {
            zeroes += (nums[end] == 0);

            while (zeroes > 1)
            {
                zeroes -= (nums[start++] == 0);
            }

            int len = end - start + 1;
            maxLen = max(maxLen, len);
        }

        return maxLen - 1;
    }
};



class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n = nums.size(), start = 0, end = 0, maxLen = 0, zeroes = 0;

        while (end < n)
        {
            zeroes += (nums[end] == 0);

            while (zeroes > 1)
            {
                zeroes -= (nums[start] == 0);
                start++;
            }

            maxLen = max(maxLen, end - start + 1);
            end++;
        }

        return maxLen - 1;
    }
};