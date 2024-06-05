// Problem Link :- https://leetcode.com/problems/find-common-characters/

// Solved using frequency vector
// Time Complexity :- O(n * m)  n = number of strings
// Space Complexity :- O(n * 26)  m = length of each string

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        
        int n = words.size();
        vector<vector<int>> freq(n, vector<int> (26, 0));

        for (int i = 0; i < n; i++)
        {
            for (auto &ch : words[i])
                freq[i][ch - 'a']++;
        }

        vector<string> commonChars;

        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            int minFreq = n;

            for (int j = 0; j < n; j++)
            {
                minFreq = min(minFreq, freq[j][ch - 'a']);
            }

            for (int k = 0; k < minFreq; k++)
                commonChars.emplace_back(string(1, ch));
        }

        return commonChars;
    }
};



// Space Optimized Solution
// Time Complexity :- O(n * m)  n = number of strings
// Space Complexity :- O(26)    m = length of each string

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        
        int n = words.size();
        vector<int> commonCharacterCounts(26, 0);
        vector<string> result;

        for (char& ch : words[0])
            commonCharacterCounts[ch - 'a']++;

        for (int i = 1; i < n; i++) 
        {
            vector<int> currentCharacterCounts(26, 0);

            for (char& ch : words[i]) 
                currentCharacterCounts[ch - 'a']++;

            for (int letter = 0; letter < 26; letter++) 
            {
                commonCharacterCounts[letter] = min(commonCharacterCounts[letter], currentCharacterCounts[letter]);
            }
        }

        for (int letter = 0; letter < 26; letter++) 
        {
            for (int commonCount = 0; commonCount < commonCharacterCounts[letter]; commonCount++) 
            {
                result.emplace_back(string(1, letter + 'a'));
            }
        }

        return result;
    }
};