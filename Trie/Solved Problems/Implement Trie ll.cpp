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

    bool containsKey (char k)
    {
        int index = k - 'a';
        return (child[index] != NULL);
    } 

    void put (char k, TrieNode* node)
    {
        int index = k - 'a';
        child[index] = node;
    }

    TrieNode* get (char k)
    {
        int index = k - 'a';
        return child[index];
    }

    void changePrefixCount (bool increase)
    {
        (increase) ? countPrefix++ : countPrefix--;
    }

    void changeWordsCount (bool increase)
    {
        (increase) ? countWords++ : countWords--;
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
            if (node->containsKey(it) == NULL)
                node->put(it, new TrieNode());

            node = node->get(it);
            node->changePrefixCount(true);
        }

        node->changeWordsCount(true);
    }

    int countWordsEqualTo(string &word){
        
        TrieNode* node = root;

        for (auto &it : word)
        {
            if (node->containsKey(it) == NULL)
                return 0;

            node = node->get(it);
        }

        return node->countWords;
    }

    int countWordsStartingWith(string &word){
        
        TrieNode* node = root;

        for (auto &it : word)
        {
            if (node->containsKey(it) == NULL)
                return 0;

            node = node->get(it);
        }

        return node->countPrefix;
    }

    void erase(string &word){
        
        TrieNode* node = root;

        for (auto &it : word)
        {
            TrieNode* parent = node;
            node = node->get(it);
            node->changePrefixCount(false);

            if (node->countPrefix == 0)
            {                
                TrieNode* del = parent->get(it);
                del = NULL;
            }
        }

        node->changeWordsCount(false);
    }
};

