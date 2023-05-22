// Problem Link :- https://leetcode.com/problems/word-ladder-ii/


// Solution that works in interview but will give TLE on Leetcode

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> dict (wordList.begin(), wordList.end());
        queue<vector<string>> BFS;
        vector<vector<string>> ladders;
        vector<string> usedOnLevel;

        usedOnLevel.emplace_back(beginWord);
        BFS.emplace(usedOnLevel);
        int level = 1;

        while (!BFS.empty())
        {
            vector<string> words = BFS.front();
            BFS.pop();

            string word = words.back();

            if (word == endWord)
            {
                if (ladders.empty() || ladders[0].size() == words.size())
                    ladders.emplace_back(words);
            }

            if (words.size() == level)
            {
                for (auto &it : usedOnLevel)
                    dict.erase(it);

                usedOnLevel.clear();    
                level++;
            }

            if (word == endWord)
                continue;

            for (int index = 0; index < word.size(); index++)
            {
                char old = word[index];

                for (char k = 'a'; k <= 'z'; k++)
                {
                    word[index] = k;

                    if (dict.find(word) != dict.end())
                    {
                        words.emplace_back(word);
                        BFS.emplace(words);
                        usedOnLevel.emplace_back(word);
                        words.pop_back();
                    }
                }

                word[index] = old;
            }
        }

        return ladders;
    }
};


// Optimized Solution that works on Leetcode

class Solution {
public:

    void DFS (string word, string &beginWord, vector<string> &path, vector<vector<string>> &ladders, unordered_map<string, int> &mp)
    {
        if (word == beginWord)
        {
            reverse(path.begin(), path.end());
            ladders.emplace_back(path);
            reverse(path.begin(), path.end());

            return;
        }

        int steps = mp[word];

        for (int index = 0; index < word.size(); index++)
        {
            char old = word[index];

            for (char k = 'a'; k <= 'z'; k++)
            {
                word[index] = k;

                if (mp.find(word) != mp.end() && mp[word] == steps - 1)
                {
                    path.emplace_back(word);
                    DFS (word, beginWord, path, ladders, mp);
                    path.pop_back();
                }
            }

            word[index] = old;
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> dict (wordList.begin(), wordList.end());
        queue<string> BFS;
        vector<vector<string>> ladders;
        unordered_map<string, int> mp;

        BFS.emplace(beginWord);
        mp[beginWord] = 1;
        dict.erase(beginWord);

        while (!BFS.empty())
        {
            string word = BFS.front();
            int steps = mp[word];
            BFS.pop();

            if (word == endWord)
                break;

            for (int index = 0; index < word.size(); index++)
            {
                char old = word[index];

                for (char k = 'a'; k <= 'z'; k++)
                {
                    word[index] = k;

                    if (dict.find(word) != dict.end())
                    {
                        BFS.emplace(word);
                        mp[word] = steps + 1;
                        dict.erase(word);
                    }
                }

                word[index] = old;
            }
        }

        if (mp.find(endWord) != mp.end())
        {
            vector<string> path;
            path.emplace_back(endWord);
            DFS (endWord, beginWord, path, ladders, mp);
        }
        

        return ladders;
    }
};