// Problem Link :- https://leetcode.com/problems/binary-subarrays-with-sum/

// Solved using unordered_map
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        int sum = 0, subarray = 0;        
        unordered_map<int, int> sumFreq;
        sumFreq[sum]++;

        for (auto &it : nums)
        {
            sum += it;
            subarray += sumFreq[sum - goal];
            sumFreq[sum]++;
        }

        return subarray;
    }
};



// Solved by Sliding Window
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:

    int slidingWindow (vector<int> &nums, int goal)
    {
        if (goal < 0)
            return 0;

        int n = nums.size(), subarrays = 0, sum = 0;

        for (int start = 0, end = 0; end < n; end++)
        {
            sum += nums[end];

            while (sum > goal)
            {
                sum -= nums[start++];
            }

            int len = end - start + 1;
            subarrays += len;
        }

        return subarrays;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {

        int ans = slidingWindow (nums, goal) - slidingWindow(nums, goal - 1);
        return ans;
    }
};