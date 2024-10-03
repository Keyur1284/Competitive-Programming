// Problem Link :- https://leetcode.com/problems/make-sum-divisible-by-p/

// Solved using unordered_map
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        
        int n = nums.size(), sum = 0;
        
        for (int i = 0; i < n; i++)
        {
            sum = (sum + nums[i]) % p;
        }

        if (sum == 0)
            return 0;

        int minLen = n, target = sum;
        sum = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;

        for (int i = 0; i < n; i++)
        {
            sum = (sum + nums[i]) % p;

            if (mp.count((sum - target + p) % p))
            {
                int len = i - mp[(sum - target + p) % p];
                minLen = min(len, minLen);
            }

            mp[sum] = i;
        }

        return minLen == n ? -1 : minLen;
    }
};