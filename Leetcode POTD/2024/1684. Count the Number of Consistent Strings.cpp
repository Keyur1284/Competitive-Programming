// Problem Link :- https://leetcode.com/problems/count-the-number-of-consistent-strings/

// Solved using unordered_set
// Time Complexity :- O(n + m * k)
// Space Complexity :- O(n)

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        int count = 0;
        unordered_set<char> allowedChars(allowed.begin(), allowed.end());

        for (auto &word : words)
        {
            bool flag = true;

            for (auto ch : word)
            {
                if (!allowedChars.count(ch))
                {
                    flag = false;
                    break;
                }
            }

            count += flag;
            
        }

        return count;
    }
};



// Solved by Bit Manipulation
// Time Complexity :- O(n + m * k)
// Space Complexity :- O(1)

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        int count = 0;
        int allowedChars = 0;

        for (auto ch : allowed)
        {
            allowedChars |= 1 << (ch - 'a');
        }

        for (auto &word : words)
        {
            bool flag = true;

            for (auto ch : word)
            {
                bool isBitSet = allowedChars & (1 << (ch - 'a'));

                if (!isBitSet)
                {
                    flag = false;
                    break;
                }
            }

            count += flag;
            
        }

        return count;
    }
};