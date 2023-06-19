// Problem Link :- https://leetcode.com/problems/longest-common-prefix/

// Solved using Trie Data Structure
// Time Complexity :- O(S)      S = no. of all characters in the array
// Space Complexity :- O(S)

class TrieNode {
public:

    int count;
    vector<TrieNode*> child;

    TrieNode ()
    {
        child.assign(26, NULL);
        count = 0;
    }
};

class Trie {
private:

    TrieNode* root;

public:
    
    Trie ()
    {
        root = new TrieNode();
    }

    void insert (string &word)
    {
        TrieNode* node = root;

        for (auto &it : word)
        {
            int index = it - 'a';

            if (node->child[index] == NULL)
                node->child[index] = new TrieNode();

            node = node->child[index];
            node->count++;
        }
    }

    string findPref (string &word, int n)
    {
        int prefLen = 0;
        TrieNode* node = root;

        for (auto &it : word)
        {
            int index = it - 'a';

            node = node->child[index];
            
            if (node->count != n)
                break;

            prefLen++;
        }

        return word.substr(0, prefLen);
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        Trie obj;
        int n = strs.size();

        for (auto &it : strs)
            obj.insert(it);

        string longestPrefix = obj.findPref(strs[0], n);

        return longestPrefix;
    }
};