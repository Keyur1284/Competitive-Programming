// Problem Link :- https://leetcode.com/problems/number-of-good-pairs/

// Solved by brute force approach
// Time Complexity :- O(n^2)
// Space Complexity :- O(1)

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        int n = nums.size(), goodPairs = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
                goodPairs += (nums[i] == nums[j]);
        }

        return goodPairs;
    }
};



// Solved by using unordered_map
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        int goodPairs = 0;
        unordered_map<int, int> mp;

        for (auto &it : nums)
        {
            goodPairs += mp[it];
            mp[it]++;
        }

        return goodPairs;
    }
};