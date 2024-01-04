// Problem Link :- https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/

// Solved using unordered_map
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        unordered_map<int, int> freq;

        for (auto &it : nums)
            freq[it]++;
        
        int ans = 0;

        for (auto &it : freq) 
        {
            if (it.second == 1) 
                return -1;
        
            ans += it.second/3;
        
            if (it.second % 3) 
                ans++;

            // Alternatively, we can write the above 2 lines as
            // ans += (it.second + 2) / 3;
        }

        return ans;
    }
};