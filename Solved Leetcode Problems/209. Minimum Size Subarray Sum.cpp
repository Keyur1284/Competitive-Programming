// Problem Link :- https://leetcode.com/problems/minimum-size-subarray-sum/

// Solved by Sliding Window
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

       int n = nums.size();
       int minLen = n + 1, sum = 0;

       for (int start = 0, end = 0; end < n; end++) 
       {
           sum += nums[end];

           while (start <= end && sum >= target)
           {
               int len = end - start + 1;
               minLen = min(minLen, len);
               sum -= nums[start++];
           }
       }

       return (minLen == n + 1) ? 0 : minLen;
    }
};



// Solved by Binary Search + Prefix Sum
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int n = nums.size();
        int minLen = n + 1;

        vector<int> pref (n + 1, 0);

        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + nums[i];

        for (int end = n; end >= 0 && pref[end] >= target; end--)
        {
            int start = upper_bound(pref.begin(), pref.end(), pref[end] - target) - pref.begin();
            minLen = min(minLen, end - start + 1);
        }

        return (minLen == n + 1) ? 0 : minLen;
    }
};