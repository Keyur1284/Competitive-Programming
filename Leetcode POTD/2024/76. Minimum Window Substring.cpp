// Problem Link :- https://leetcode.com/problems/minimum-window-substring/

// Solved by Sliding Window Approach
// Time Complexity :- O(n + m)
// Space Complexity :- O(26)

class Solution {
public:
    string minWindow(string s, string t) {
        
        int m = s.length(), n = t.length(), minStart = -1, minLen = 1e6, count = n;
        unordered_map<char, int> tmap;

        for (auto &c : t)
            tmap[c]++;

        for (int left = 0, right = 0; right < m; right++)
        {
            if (tmap[s[right]] > 0)
                count--;

            tmap[s[right]]--;

            while (count == 0)
            {
                int len = right - left + 1;

                if (len < minLen)
                {
                    minStart = left;
                    minLen = len;
                }

                tmap[s[left]]++;

                if (tmap[s[left]] > 0)
                    count++;

                left++;
            }
        }

        return (minLen == 1e6 ? "" : s.substr(minStart, minLen));
    }
};