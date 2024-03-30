// Problem Link :- https://leetcode.com/problems/subarrays-with-k-different-integers/

// Solved using Sliding Window Approach
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:

    int slidingWindow (vector<int>& nums, int k)
    {
        unordered_map<int, int> mp;
        int n = nums.size(), subarrays = 0;

        for (int start = 0, end = 0; end < n; end++)
        {
            mp[nums[end]]++;

            while (mp.size() > k)
            {
                mp[nums[start]]--;

                if (mp[nums[start]] == 0)
                    mp.erase(nums[start]);

                start++;
            }

            int len = end - start + 1;
            subarrays += len;
        }

        return subarrays;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        int ans = slidingWindow(nums, k) - slidingWindow(nums, k - 1);
        return ans;
    }
};



// Solved in one pass
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;
        int n = nums.size(), subarrays = 0, extra = 0;

        for (int start = 0, end = 0; end < n; end++)
        {
            mp[nums[end]]++;

            while (mp.size() > k)
            {
                mp[nums[start]]--;

                if (mp[nums[start]] == 0)
                    mp.erase(nums[start]);

                start++;
                extra = 0;
            }

            if (mp.size() == k)
            {
                while (mp[nums[start]] > 1)
                {
                    extra++;
                    mp[nums[start++]]--;
                }

                subarrays += extra + 1;
            }
        }

        return subarrays;
    }
};