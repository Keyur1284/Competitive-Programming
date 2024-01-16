// Problem Link :- https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/

// Solved by traversing string
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int minSteps(string s, string t) {
        
        vector<int> freq(26, 0);
        int n = s.size(), ans = 0;

        for (int i = 0; i < n; i++)
        {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++)
        {
            if (freq[i] > 0)
                ans += freq[i];
        }

        return ans;
    }
};