// Problem Link :- https://leetcode.com/problems/continuous-subarray-sum/

// Solved using unordered_map
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        int n = nums.size(), sum = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            sum %= k;

            if (mp.count(sum))
            {
                if (i - mp[sum] > 1)
                    return true;
            }

            else
                mp[sum] = i;
        }

        return false;
    }
};