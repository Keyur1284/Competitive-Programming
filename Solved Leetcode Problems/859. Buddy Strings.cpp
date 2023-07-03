// Problem Link :- https://leetcode.com/problems/buddy-strings/

// Solved by traversing
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        
        int diff = 0, sLen = s.length(), goalLen = goal.length();
        
        if (sLen != goalLen)
            return false;

        vector<int> freq(26, 0);

        for (int i = 0; i < sLen; i++)
        {
            diff += (s[i] != goal[i]);
            freq[s[i] - 'a']++;
            freq[goal[i] - 'a']--;
        }

        for (auto &it : freq)
        {
            if (it)
                return false;
        }

        if (diff == 2)
            return true;

        if (diff > 2 || diff == 1)
            return false;

        for (int i = 0; i < sLen; i++)
        {
            freq[s[i] - 'a']++;
        }

        for (auto &it : freq)
        {
            if (it >= 2)
                return true;
        }

        return false;
    }
};



class Solution {
public:
    bool buddyStrings(string s, string goal) {
        
        int diff = 0, sLen = s.length(), goalLen = goal.length();
        
        if (sLen != goalLen)
            return false;

        if (s == goal)
        {
            vector<int> freq(26, 0);

            for (int i = 0; i < sLen; i++)
            {
                freq[s[i] - 'a']++;

                if (freq[s[i] - 'a'] == 2)
                    return true;
            }

            return false;
        }

        int firstIndex = -1, secondIndex = -1;

        for (int i = 0; i < sLen; i++)
        {
            if (s[i] != goal[i])
            {
                if (firstIndex == -1)
                    firstIndex = i;

                else if (secondIndex == -1)
                    secondIndex = i;

                else
                    return false;
            }
        }

        if (secondIndex == -1)
            return false;

        return (s[firstIndex] == goal[secondIndex] && s[secondIndex] == goal[firstIndex]);
    }
};