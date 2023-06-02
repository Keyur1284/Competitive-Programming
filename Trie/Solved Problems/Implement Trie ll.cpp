// Problem Link :- https://www.codingninjas.com/codestudio/problems/implement-trie_1387095

// Insert and Erase
// Time Complexity :- O(N)
// Space Complexity :- O(N)

// CountWords and CountPrefix
// Time Complexity :- O(N)
// Space Complexity :- O(1)

#include <bits/stdc++.h> 

class TrieNode {

    public:

    int countWords, countPrefix;
    vector<TrieNode*> child;

    TrieNode ()
    {
        countWords = 0;
        countPrefix = 0;
        child.assign (26, NULL);
    }
};

class Trie{

    public:

    TrieNode* root;

    Trie(){
        
        root = new TrieNode();
    }

    void insert(string &word){
        
        TrieNode* node = root;

        for (auto &it : word)
        {
            int index = it - 'a';

            if (node->child[index] == NULL)
                node->child[index] = new TrieNode();

            node = node->child[index];
            node->countPrefix++;
        }

        node->countWords++;
    }

    int countWordsEqualTo(string &word){
        
        TrieNode* node = root;

        for (auto &it : word)
        {
            int index = it - 'a';

            if (node->child[index] == NULL)
                return 0;

            node = node->child[index];
        }

        return node->countWords;
    }

    int countWordsStartingWith(string &word){
        
        TrieNode* node = root;

        for (auto &it : word)
        {
            int index = it - 'a';

            if (node->child[index] == NULL)
                return 0;

            node = node->child[index];
        }

        return node->countPrefix;
    }

    void erase(string &word){
        
        TrieNode* node = root;

        for (auto &it : word)
        {
            int index = it - 'a';

            node = node->child[index];
            node->countPrefix--;
        }

        node->countWords--;
    }
};
