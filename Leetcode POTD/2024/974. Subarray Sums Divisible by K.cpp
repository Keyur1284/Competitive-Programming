// Problem Link :- https://leetcode.com/problems/subarray-sums-divisible-by-k/

// Solved using unordered_map
// Time Complexity :- O(n)
// Space Complexity :- O(k)

class Solution {
public:

    int subarraysDivByK(vector<int>& nums, int k) {

        int n = nums.size(), sum = 0, count = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;

        for (int i = 0; i < n; i++)
        {
            sum = (sum + nums[i] % k + k) % k;
            count += mp[sum]++;
        }

        return count;
    }
};