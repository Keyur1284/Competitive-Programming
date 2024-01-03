// Problem Link :- https://leetcode.com/problems/valid-anagram/

// Solved by sorting
// Time Complexity :- O(nlogn)
// Space Complexity :- O(logn)

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int n = s.length(), m = t.length();

        if (n != m)
            return false;

        sort (s.begin(), s.end());
        sort (t.begin(), t.end());

        return (s == t);
    }
};



// Solved by counting frequency of characters
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int n = s.length(), m = t.length();

        if (n != m)
            return false;

        vector<int> freq(26, 0);

        for (int i = 0; i < n; i++)
        {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        for (auto &it : freq)
        {
            if (it != 0)
                return false;
        }

        return true;
    }
};