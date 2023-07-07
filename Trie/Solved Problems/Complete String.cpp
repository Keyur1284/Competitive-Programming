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

    void increaseWordsCount ()
    {
        countWords++;
    }

    int getWordsCount()
    {
        return countWords;
    }
};

class Trie {

    TrieNode* root;

public:

    Trie ()
    {
        root = new TrieNode();
    }

    void insert(string &word)
    {
        TrieNode* node = root;

        for (auto &it : word)
        {
            if (node->containsKey(it) == NULL)
                node->put(it, new TrieNode());

            node = node->get(it);
        }

        node->increaseWordsCount();
    }

    bool search (string &word)
    {
        TrieNode* node = root;

        for (auto &it : word)
        {
            node = node->get(it);
            
            if (node->getWordsCount() == 0)
                return false;
        }

        return true;
    }
};


string completeString(int n, vector<string> &a){
    
    Trie obj;    

    for (auto &str : a)
    {
        obj.insert(str);
    }

    string ans = "";

    for (auto &str : a)
    {
        if (obj.search(str))
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

    bool flag;
    vector<TrieNode*> child;

    TrieNode ()
    {
        flag = false;
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

    void setEnd ()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
};

class Trie {

    TrieNode* root;

public:

    Trie ()
    {
        root = new TrieNode();
    }

    void insert(string &word)
    {
        
        TrieNode* node = root;

        for (auto &it : word)
        {
            if (node->containsKey(it) == NULL)
                node->put(it, new TrieNode());

            node = node->get(it);
        }

        node->setEnd();
    }

    bool search (string &word)
    {
        TrieNode* node = root;

        for (auto &it : word)
        {
            node = node->get(it);
            
            if (node->isEnd() == false)
                return false;
        }

        return true;
    }
};

string completeString(int n, vector<string> &a){

    Trie obj;    

    for (auto &str : a)
    {
        obj.insert(str);
    }

    string ans = "";

    for (auto &str : a)
    {
        if (obj.search(str))
        {
            if (ans.length() < str.length())
                ans = str;

            else if (ans.length() == str.length())
                ans = min(ans, str);
        }
    }

    return (ans.size()) ? ans : "None";
}