// Problem Link :- https://leetcode.com/problems/word-break-ii/

// Solved by Backtracking
// Time Complexity :- O(2^n)
// Space Complexity :- O(2^n)

class Solution {
public:
            
    void solve (int start, string path, int &n, vector<string> &sentence, string &s, unordered_set<string> &words)
    {
        if (start == n)
        {
            sentence.emplace_back(path);
            return;
        }

        path += " ";
        string str = "";

        for (int end = start; end < n; end++)
        {
            str += s[end];

            if (words.count(str))
                solve (end + 1, path + str, n, sentence, s, words);
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
    
        int n = s.length();
        unordered_set<string> words(wordDict.begin(), wordDict.end());

        string t = "";
        vector<string> sentence;

        for (int index = 0; index < n; index++)
        {
            t += s[index];

            if (words.count(t))
                solve (index + 1, t, n, sentence, s, words);
        }

        return sentence;
    }
};



// Solved by Dynamic Programming
// Time Complexity :- O(n^2)
// Space Complexity :- O(n^2)

class Solution {
public:
    
    vector<string> solve (int start, int n, string &s, unordered_set<string> &words, unordered_map<int, vector<string>> &dp)
    {
        if (start == n)
            return {""};

        if (dp.count(start))
            return dp[start];

        string str = "";
        vector<string> sentence;

        for (int end = start; end < n; end++)
        {
            str += s[end];

            if (words.count(str))
            {
                vector<string> temp = solve (end + 1, n, s, words, dp);

                for (string &t : temp)
                    sentence.emplace_back(str + (t.empty() ? "" : " ") + t);
            }
        }

        return dp[start] = sentence;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
    
        int n = s.length();
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> dp;

        return solve (0, n, s, words, dp);
    }
};



// Solved using Trie
// Time Complexity :- O(2^n)
// Space Complexity :- O(2^n)

class TrieNode {
public:

    bool isEnd;
    vector<TrieNode*> child;

    TrieNode ()
    {
        isEnd = false;
        child.assign(26, NULL);
    }
};

class Trie {
public:

    TrieNode* root;

    Trie() 
    {
        
        root = new TrieNode();
    }
    
    void insert(string &word) {
        
        TrieNode* node = root;

        for (auto &it : word)
        {
            int index = it - 'a';

            if (node->child[index] == NULL)
                node->child[index] = new TrieNode();

            node = node->child[index];
        }

        node->isEnd = true;
    }

    bool search(string word) {
        
        TrieNode* node = root;

        for (auto &it : word)
        {
            int index = it - 'a';

            if (node->child[index] == NULL)
                return false;

            node = node->child[index];
        }

        return node->isEnd;
    }
};

class Solution {
public:
            
    Trie obj;

    void solve (int start, string path, vector<string> &sentence, string &s)
    {
        if (start == s.length())
        {
            sentence.emplace_back(path);
            return;
        }

        path += " ";
        string str = "";

        for (int end = start; end < s.length(); end++)
        {
            str += s[end];

            if (obj.search(str))
                solve (end + 1, path + str, sentence, s);
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
    
        for (auto &word : wordDict)
            obj.insert(word);

        int n = s.length();
        string t = "";
        vector<string> sentence;

        for (int index = 0; index < n; index++)
        {
            t += s[index];

            if (obj.search(t))
                solve (index + 1, t, sentence, s);
        }

        return sentence;
    }
};