// Problem Link :- https://leetcode.com/problems/word-break/

// Solved by DP
// Time Complexity :- O(n^2)
// Space Complexity :- O(n)

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

        string t = "";
        vector<int> dp(n, -1);

        for (int index = 0; index < n; index++)
        {
            t += s[index];

            if (words.find(t) != words.end())
                if (solve (index + 1, dp, s, words))
                    return true;
        }

        return false;
    }
};



// Solved by Trie Data Structure
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