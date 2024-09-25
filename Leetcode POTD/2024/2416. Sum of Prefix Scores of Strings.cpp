// Problem Link :- https://leetcode.com/problems/sum-of-prefix-scores-of-strings/

// Solved using Trie
// Time Complexity :- O(n * m)  n = no. of strings
// Space Complexity :- O(n * m) m = avg. length of strings

class TrieNode {
public:

    int prefCount;
    unordered_map<int, TrieNode*> child;

    TrieNode()
    {
        prefCount = 0;
    }
};

class Trie {
public:

    TrieNode* root;

    Trie()
    {
        root = new TrieNode();
    }

    void insert(string &s)
    {
        TrieNode* curr = root;

        for (auto ch : s)
        {
            if (!curr->child.count(ch - 'a'))
                curr->child[ch - 'a'] = new TrieNode();

            curr = curr->child[ch - 'a'];
            curr->prefCount++;
        }
    }

    int findScore(string &s)
    {
        TrieNode* curr = root;
        int score = 0;

        for (auto ch : s)
        {
            if (!curr->child.count(ch - 'a'))
                break;

            curr = curr->child[ch - 'a'];
            score += curr->prefCount;
        }

        return score;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        
        Trie trie;
        vector<int> prefScore;

        for (auto &str : words)
            trie.insert(str);

        for (auto &str : words)
            prefScore.emplace_back(trie.findScore(str));

        return prefScore;
    }
};