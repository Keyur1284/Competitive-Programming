// Problem Link :- https://leetcode.com/problems/rotate-array/

// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> ans(n);

        for (int i = 0; i < n; i++)
        {
            ans[(i + k) % n] = nums[i];
        }

        nums = ans;
    }
};


// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        k %= n;
        
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
