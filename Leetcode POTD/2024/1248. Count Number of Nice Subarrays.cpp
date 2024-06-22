// Problem Link :- https://leetcode.com/problems/count-number-of-nice-subarrays/

// Solved by Sliding Window
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int n = nums.size(), subarrays = 0;

        for (auto &it : nums)
        {
            it &= 1;
        }

        unordered_map<int, int> sumFreq;
        sumFreq[0]++;
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            subarrays += sumFreq[sum - k];
            sumFreq[sum]++;
        }

        return subarrays;
    }
};



class Solution {
public:

    int slidingWindow (vector<int>& nums, int k)
    {
        int n = nums.size();
        int odd = 0, subarrays = 0;
        
        for (int start = 0, end = 0; end < n; end++)
        {
            odd += (nums[end] & 1);

            while (odd > k)
            {
                odd -= (nums[start++] & 1);
            }
            
            int len = end - start + 1;
            subarrays += len;
        }

        return subarrays;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int ans = slidingWindow (nums, k) - slidingWindow(nums, k - 1);
        return ans;
    }
};



class Solution {
public:

    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int subarrays = 0, n = nums.size(), odd = 0, count = 0;

        for (int start = 0, end = 0; end < n; end++)
        {
            if (nums[end] & 1)
            {
                odd++;
                count = 0;
            }

            while (odd >= k)
            {
                odd -= (nums[start++] & 1);
                count++;
            }

            subarrays += count;
        }

        return subarrays;
    }
};