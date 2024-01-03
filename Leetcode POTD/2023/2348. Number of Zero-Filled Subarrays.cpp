// Problem Link :- https://leetcode.com/problems/number-of-zero-filled-subarrays/

// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {

        long long ans = 0, count = 0;

        for (auto &it : nums)
        {
            if (it == 0)
                count++;

            else if (count > 0)
            {
                ans += (count + 1) * count/2;
                count = 0;
            }
        }
        
        if (count > 0)
            ans += (count + 1) * count/2;

        return ans;
    }
};


class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {

        long long ans = 0, count = 0;

        for (auto &it : nums)
        {
            if (it == 0)
                count++;

            else
                count = 0;
            
            ans += count;
        }

        return ans;
    }
};