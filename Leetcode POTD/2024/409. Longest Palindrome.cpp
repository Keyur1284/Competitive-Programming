// Problem Link :- https://leetcode.com/problems/longest-palindrome/

// Solved using unordered_map
// Time Complexity :- O(n)
// Space Complexity :- O(26 + 26) = O(1)

class Solution {
public:
    int longestPalindrome(string s) {
        
        unordered_map<char, int> freq;

        for (auto &ch : s)
            freq[ch]++;

        int longestPal = 0, oddFreq = 0;

        for (auto &it : freq)
        {
            if (it.second & 1)
            {
                longestPal += it.second - 1;
                oddFreq = 1;
            }

            else
                longestPal += it.second;
        } 

        return longestPal + oddFreq;
    }
};



class Solution {
public:
    int longestPalindrome(string s) {
        
        int n = s.length(), oddFreqCount = 0;
        unordered_map<char, int> freq;

        for (auto &ch : s)
        {
            freq[ch]++;
            oddFreqCount += (freq[ch] & 1) ? 1 : -1;
        }

        return n - oddFreqCount + (oddFreqCount > 0);
    }
};



// Solved using unordered_set
// Time Complexity :- O(n)
// Space Complexity :- O(26 + 26) = O(1)

class Solution {
public:
    int longestPalindrome(string s) {
        
        unordered_set<char> freq;
        int longestPal = 0;

        for (auto &ch : s)
        {
            if (freq.count(ch))
            {
                freq.erase(ch);
                longestPal += 2;
            }

            else
                freq.emplace(ch);
        }

        return longestPal + (freq.size() > 0);
    }
};