//Problem Link :- https://leetcode.com/problems/largest-divisible-subset/


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n = nums.size(), maxi = INT_MIN, last = 0;
        sort(nums.begin(), nums.end());
        
        vector <int> dp(n, 1), hash(n);
        
        for (int index = 0; index < n; index++)
        {
            hash[index] = index;
            
            for (int prev = 0; prev < index; prev++)
            {
                if (nums[index] % nums[prev] == 0 && 1 + dp[prev] > dp[index])
                {
                    dp[index] = 1 + dp[prev];
                    hash[index] = prev;
                }
                
                if (dp[index] > maxi)
                {
                    maxi = dp[index];
                    last = index;
                }
            }
        }
        
        vector <int> ans;
        ans.emplace_back(nums[last]);
        
        while (last != hash[last])
        {
            last = hash[last];
            ans.emplace_back(nums[last]);
        }
        
        reverse(ans.begin(), ans.end());        //  This can be omitted as we need to print any subset
        
        return ans;
    }
};
