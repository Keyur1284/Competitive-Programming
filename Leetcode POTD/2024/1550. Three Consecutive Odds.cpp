// Problem Link :- https://leetcode.com/problems/three-consecutive-odds/

// Solved by Brute Force Approach
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        
        int n = arr.size();

        for (int i = 0; i <= n - 3; i++)
        {
            if (arr[i] & arr[i + 1] & arr[i + 2] & 1)
                return true;
        }

        return false;
    }
};