// Problem Link :- https://leetcode.com/problems/word-break-ii/

// Solved using Trie Data Structure
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

    void solve (int start, string path, vector<string> &sent, string &s)
    {
        if (start == s.length())
        {
            sent.emplace_back(path);
            return;
        }

        path += " ";
        string str = "";

        for (int end = start; end < s.length(); end++)
        {
            str += s[end];

            if (obj.search(str))
                solve (end + 1, path + str, sent, s);
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
    
        for (auto &word : wordDict)
            obj.insert(word);

        int n = s.length();
        string t = "";
        vector<string> sent;

        for (int index = 0; index < n; index++)
        {
            t += s[index];

            if (obj.search(t))
                solve (index + 1, t, sent, s);
        }

        return sent;
    }
};