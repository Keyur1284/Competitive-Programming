// Problem Link :- https://leetcode.com/problems/contiguous-array/

// Solved using unordered_map
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = -1;

        int currCount = 0, maxLen = 0;

        for (int i = 0; i < n; i++)
        {
            currCount += (nums[i] == 1) ? 1 : -1;

            if (mp.count(currCount))
            {
                int len = i - mp[currCount];
                maxLen = max(maxLen, len);
            }

            else
                mp[currCount] = i;
        }

        return maxLen;
    }
};



// Solved using vector
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> mp(2 *n + 1, -2);
        mp[0 + n] = -1;

        int currCount = 0, maxLen = 0;

        for (int i = 0; i < n; i++)
        {
            currCount += (nums[i] == 1) ? 1 : -1;

            if (mp[currCount + n] != -2)
            {
                int len = i - mp[currCount + n];
                maxLen = max(maxLen, len);
            }

            else
                mp[currCount + n] = i;
        }

        return maxLen;
    }
};