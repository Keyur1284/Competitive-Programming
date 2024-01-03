// Problem Link :- https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/

// Solved using unordered_map
// Time Complexity :- O(n + m * k)  n = length of chars, m = length of words
// Space Complexity :- O(1)         k = average length of each word

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        
        unordered_map<char, int> dict;

        for (auto &it : chars)
            dict[it]++;

        int sum = 0;

        for (auto &word : words)
        {
            unordered_map<char, int> freq;

            for (auto &k : word)
                freq[k]++;

            bool good = true;

            for (char k = 'a'; k <= 'z'; k++)
            {
                if (freq[k] > dict[k])
                {
                    good = false;
                    break;
                }
            }

            if (good)
                sum += word.size();
        }

        return sum;
    }
};