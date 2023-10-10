// Problem Link :- https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/

// Solved by Binary Search
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:
    int minOperations(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(), nums.end());
        nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
        int newn = nums.size(), minOps = n;

        for (int i = 0; i < newn; i++)
        {
            int left = nums[i], right = left + n - 1;
            int j = upper_bound(nums.begin(), nums.end(), right) - nums.begin();
            int valid = j - i;
            int ops = n - valid;
            minOps = min(minOps, ops);
        }

        return minOps;
    }
};



// Solved by Sliding Window
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:
    int minOperations(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(), nums.end());
        nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
        int newn = nums.size(), minOps = n;

        for (int i = 0, j = 0; i < newn; i++)
        {
            int left = nums[i], right = left + n - 1;
            
            while (j < newn && nums[j] <= right)
                j++;

            int valid = j - i;
            int ops = n - valid;
            minOps = min(minOps, ops);
        }

        return minOps;
    }
};