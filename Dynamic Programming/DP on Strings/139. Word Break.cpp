// Problem Link :- https://leetcode.com/problems/word-break/

// Solved by Memoization Method
// Time Complexity :- O(n^2)        n = length of string
// Space Complexity :- O(n + m)     m = no. of words in wordDict

class Solution {
public:

    bool solve (int start, vector<int> &dp, string &s, unordered_set<string> &words)
    {
        if (start == s.length())
            return true;

        if (dp[start] != -1)
            return dp[start];

        string str = "";

        for (int end = start; end < s.length(); end++)
        {
            str += s[end];

            if (words.find(str) != words.end())
                if (solve (end + 1, dp, s, words))
                    return dp[start] = true;
        }

        return dp[start] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.length();
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<int> dp(n, -1);

        return solve (0, dp, s, words);
    }
};



// Solved by Tabulation Method
// Time Complexity :- O(n^2)        n = length of string
// Space Complexity :- O(n + m)     m = no. of words in wordDict

class Solution {
public:

    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        unordered_set<string> words(wordDict.begin(), wordDict.end());

        for (int end = 1; end <= n; end++)
        {
            for (int start = 0; start < end; start++)
            {
                if (words.find(s.substr(start, end - start)) != words.end() && dp[start])
                {
                    dp[end] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};



// Solved by DFS
// Time Complexity :- O(n^2)        n = length of string
// Space Complexity :- O(n + m)     m = no. of words in wordDict

class Solution {
public:

    bool dfs(string &s, unordered_set<string>& words, int start, vector<bool>& vis)
    {
        if (start == s.size())
            return true;

        if (!vis[start])
        {
            for (int end = start; end < s.size(); end++)
            {
                if (words.find(s.substr(start, end - start + 1)) != words.end())
                {
                    if (dfs(s, words, end + 1, vis))
                        return true;
                }
            }

            vis[start] = true;
        }

        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        int n = s.size();
        vector<bool> vis(n, false);
        unordered_set<string> words(wordDict.begin(), wordDict.end());

        return dfs(s, words, 0, vis);
    }
};



// Solved by BFS
// Time Complexity :- O(n^2)        n = length of string
// Space Complexity :- O(n + m)     m = no. of words in wordDict

class Solution {
public:

    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.size();
        vector<int> vis(n, 0);
        unordered_set<string> words(wordDict.begin(), wordDict.end());

        queue<int> q;
        q.emplace(0);

        while (!q.empty())
        {
            int start = q.front();
            q.pop();

            if (!vis[start])
            {
                for (int end = start; end < n; end++)
                {
                    if(words.find(s.substr(start, end - start + 1)) != words.end())
                    {
                        q.emplace(end + 1);

                        if (end == n - 1)
                            return true;
                    }
                }

                vis[start] = 1;
            }

        }

        return false;
    }
};



// Solved by Trie
// Time Complexity :- O(n^2 + m * k)
// Space Complexity :- O(n + m * k)

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
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        Trie obj;

        for (auto &word : wordDict)
            obj.insert(word);

        int n = s.size();
        vector<bool> dp(n, false);

        for (int start = 0; start < n; start++)
        {
            if (start == 0 || dp[start - 1])
            {
                TrieNode* node = obj.root;

                for (int end = start; end < n; end++)
                {
                    int index = s[end] - 'a';

                    if (node->child[index] == NULL)
                        break;

                    node = node->child[index];
                    dp[end] = dp[end] || node->isEnd;
                }
            }
        }

        return dp[n - 1];
    }
};