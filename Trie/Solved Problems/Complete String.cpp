// Problem Link :- https://www.codingninjas.com/codestudio/problems/complete-string_2687860

// Solved by Advanced Trie Data Structure

// Time Complexity :- O(N * M)      N -> No. of words, M -> Length of longest word
// Space Complexity :- O(N)

#include <bits/stdc++.h> 

class TrieNode {

    public:

    int countWords;
    vector<TrieNode*> child;

    TrieNode ()
    {
        countWords = 0;
        child.assign (26, NULL);
    }
};

TrieNode* root;

void insert(string &word){
        
    TrieNode* node = root;

    for (auto &it : word)
    {
        int index = it - 'a';

        if (node->child[index] == NULL)
            node->child[index] = new TrieNode();

        node = node->child[index];
    }

    node->countWords++;
}

bool search (string &word)
{
    TrieNode* node = root;

    for (auto &it : word)
    {
        int index = it - 'a';

        node = node->child[index];

        if (node->countWords == 0)
            return false;
    }

    return true;
}

string completeString(int n, vector<string> &a){
    
    root = new TrieNode();

    for (auto &str : a)
    {
        insert(str);
    }

    string ans = "";

    for (auto &str : a)
    {
        if (search(str))
        {
            if (ans.length() < str.length())
                ans = str;

            else if (ans.length() == str.length())
                ans = min(ans, str);
        }
    }

    return (ans.size()) ? ans : "None";
}



// Solved by Trie Data Structure

#include <bits/stdc++.h> 

class TrieNode {

    public:

    bool isEnd;
    vector<TrieNode*> child;

    TrieNode ()
    {
        isEnd = false;
        child.assign (26, NULL);
    }
};

TrieNode* root;

void insert(string &word){
        
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

bool search (string &word)
{
    TrieNode* node = root;

    for (auto &it : word)
    {
        int index = it - 'a';

        node = node->child[index];

        if (node->isEnd == false)
            return false;
    }

    return true;
}

string completeString(int n, vector<string> &a){
    
    root = new TrieNode();

    for (auto &str : a)
    {
        insert(str);
    }

    string ans = "";

    for (auto &str : a)
    {
        if (search(str))
        {
            if (ans.length() < str.length())
                ans = str;

            else if (ans.length() == str.length())
                ans = min(ans, str);
        }
    }

    return (ans.size()) ? ans : "None";
}