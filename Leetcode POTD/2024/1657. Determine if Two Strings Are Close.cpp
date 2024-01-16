// Problem Link :- https://leetcode.com/problems/determine-if-two-strings-are-close/

// Solved by counting frequency of characters
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        vector<int> freq1(26, 0), freq2(26, 0);
        int n = word1.size(), m = word2.size();

        if (n != m)
            return false;

        for (int i = 0; i < n; i++)
        {
            freq1[word1[i] - 'a']++;
            freq2[word2[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++)
        {
            if ((freq1[i] == 0 && freq2[i] != 0) || (freq1[i] != 0 && freq2[i] == 0))
                return false;
        }

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        for (int i = 0; i < 26; i++)
        {
            if (freq1[i] != freq2[i])
                return false;
        }

        return true;
    }
};



class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        int n = word1.length(), m = word2.length();

        if (n != m)
            return false;

        vector<int> freq1(26, 0), freq2(26, 0);
        vector<bool> isPresent1(26, false), isPresent2(26, false);

        for (int i = 0; i < n; i++)
        {
            int index1 = word1[i] - 'a';
            int index2 = word2[i] - 'a';

            freq1[index1]++;
            freq2[index2]++;
            isPresent1[index1] = true;
            isPresent2[index2] = true;
        }

        sort (freq1.begin(), freq1.end());
        sort (freq2.begin(), freq2.end());

        return (freq1 == freq2 && isPresent1 == isPresent2);
    }
};