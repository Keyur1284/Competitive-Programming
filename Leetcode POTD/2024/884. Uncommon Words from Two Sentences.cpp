// Problem Link :- https://leetcode.com/problems/uncommon-words-from-two-sentences/

// Solved using string stream and map
// Time Complexity :- O(m + n)
// Space Complexity :- O(m + n)

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        
        unordered_map<string, int> mp1, mp2;
        stringstream ss1(s1), ss2(s2);
        vector<string> uncommonWords;
        string word;

        while(getline(ss1, word, ' '))
            mp1[word]++;

        while(getline(ss2, word, ' '))
            mp2[word]++;

        for (auto &[word, freq] : mp1)
        {
            if (freq == 1 && !mp2.count(word))
                uncommonWords.emplace_back(word);
        }

        for (auto &[word, freq] : mp2)
        {
            if (freq == 1 && !mp1.count(word))
                uncommonWords.emplace_back(word);
        }

        return uncommonWords;
    }
};



class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        
        unordered_map<string, int> mp;
        stringstream ss1(s1), ss2(s2);
        vector<string> uncommonWords;
        string word;

        while(getline(ss1, word, ' '))
            mp[word]++;

        while(getline(ss2, word, ' '))
            mp[word]++;

        for (auto &[word, freq] : mp)
        {
            if (freq == 1)
                uncommonWords.emplace_back(word);
        }

        return uncommonWords;
    }
};