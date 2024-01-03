// Problem Link :- https://leetcode.com/problems/count-number-of-homogenous-substrings/

// Solved by Maths
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:

    int MOD = 1e9 + 7;

    int countHomogenous(string s) {

        int ans = 1, count = 1, n = s.length();

        for (int i = 1; i < n; i++)
        {
            (s[i] == s[i - 1]) ? count++ : count = 1;
            ans = (ans + count) % MOD;
        }

        return ans;
    }
};