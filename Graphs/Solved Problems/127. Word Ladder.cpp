// Problem Link :- https://leetcode.com/problems/word-ladder/

// Time Complexity :- O(N ^ 2 * M * 26)     N = wordList.size(), M = wordList[i].size()
// Space Complexity :- O(N)

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> dict (wordList.begin(), wordList.end());
        
        if (dict.find(endWord) == dict.end())
            return 0;

        queue<pair<string, int>> BFS;

        BFS.emplace(beginWord, 1);
        dict.erase(beginWord);

        while (!BFS.empty())
        {
            string word = BFS.front().first;
            int steps = BFS.front().second;
            BFS.pop();

            if (word == endWord)
                return steps;

            for (int index = 0; index < word.size(); index++)
            {
                char old = word[index];

                for (char k = 'a'; k <= 'z'; k++)
                {
                    word[index] = k;

                    if (dict.find(word) != dict.end())
                    {
                        BFS.emplace(word, steps + 1);
                        dict.erase(word);
                    }
                }

                word[index] = old;
            }
        }

        return 0;
    }
};