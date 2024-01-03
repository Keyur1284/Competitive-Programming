// Problem Link :- https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/

// Solved by Prefix Sum
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum - x;

        if (target == 0)
            return n;

        unordered_map<int, int> mp;
        mp[0] = -1;

        int maxLen = 0, currSum = 0;

        for (int i = 0; i < n; i++)
        {
            currSum += nums[i];

            if (mp.find(currSum - target) != mp.end())
            {
                int len = i - mp[currSum - target];
                maxLen = max(maxLen, len);
            }

            mp[currSum] = i;
        }

        return (maxLen ? n - maxLen : -1);
    }
};



// Solved by Sliding Window
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum - x;

        if (target == 0)
            return n;

        int maxLen = 0, currSum = 0;

        for (int left = 0, right = 0; right < n; right++)
        {
            currSum += nums[right];

            while (left <= right && currSum > target)
                currSum -= nums[left++];

            if (currSum == target)
            {
                int len = right - left + 1;
                maxLen = max(maxLen, len);
            }
        }

        return (maxLen ? n - maxLen : -1);
    }
};