// Problem Link :- https://leetcode.com/problems/subarray-sum-equals-k/

// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n = nums.size(), sum = 0, ans = 0;
        unordered_map <int, int> mp;
        mp[0]++;
        
        for (auto &it : nums)
        {
            sum += it;

            if (mp.find(sum - k) != mp.end())
                ans += mp[sum - k];

            mp[sum]++;
        }

        return ans;
    }
};
