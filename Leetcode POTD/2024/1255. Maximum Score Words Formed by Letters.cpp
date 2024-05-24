// Problem Link :- https://leetcode.com/problems/maximum-score-words-formed-by-letters/

// Solved by Bitmasking
// Time Complexity :- O((n * l + 26) * 2^n)    n = number of words, l = average length of words
// Space Complexity :- O(26)

class Solution {
public:

    int findSubsetScore (vector<int> &subsetFreq, vector<int> &freq, vector<int> &score)
    {
        int subsetScore = 0;

        for (int i = 0; i < 26; i++)
        {
            if (subsetFreq[i] > freq[i])
                return 0;

            subsetScore += subsetFreq[i] * score[i];
        }

        return subsetScore;
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        
        int n = words.size();
        vector<int> freq(26, 0);

        for (auto &it : letters)
            freq[it - 'a']++;

        int maxSubsetScore = 0;

        for (int mask = 0; mask < (1 << n); mask++)
        {
            vector<int> subsetFreq(26, 0);

            for (int i = 0; i < n; i++)
            {
                if (mask & (1 << i))
                {
                    for (auto &it : words[i])
                        subsetFreq[it - 'a']++;
                }
            }

            int subsetScore = findSubsetScore(subsetFreq, freq, score);
            maxSubsetScore = max(subsetScore, maxSubsetScore);
        }

        return maxSubsetScore;
    }
};



// Solved by Backtracking
// Time Complexity :- O((n * l + 26) * 2^n)    n = number of words, l = average length of words
// Space Complexity :- O(26)

class Solution {
public:

    int maxSubsetScore = 0;

    int findSubsetScore (vector<int> &subsetFreq, vector<int> &freq, vector<int> &score)
    {
        int subsetScore = 0;

        for (int i = 0; i < 26; i++)
        {
            if (subsetFreq[i] > freq[i])
                return 0;

            subsetScore += subsetFreq[i] * score[i];
        }

        return subsetScore;
    }

    void findMaxScore (int index, int &n, vector<string> &words, vector<char> &letters, vector<int> &score, vector<int> &freq, vector<int> &subsetFreq)
    {
        if (index == n)
        {
            int subsetScore = findSubsetScore(subsetFreq, freq, score);
            maxSubsetScore = max(subsetScore, maxSubsetScore);
            return;
        }

        findMaxScore(index + 1, n, words, letters, score, freq, subsetFreq);

        for (auto &it : words[index])
            subsetFreq[it - 'a']++;

        findMaxScore(index + 1, n, words, letters, score, freq, subsetFreq);

        for (auto &it : words[index])
            subsetFreq[it - 'a']--;
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        
        int n = words.size();
        vector<int> freq(26, 0);

        for (auto &it : letters)
            freq[it - 'a']++;

        vector<int> subsetFreq(26, 0);

        findMaxScore(0, n, words, letters, score, freq, subsetFreq);

        return maxSubsetScore;
    }
};