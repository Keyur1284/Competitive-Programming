// Problem Link :- https://leetcode.com/problems/longest-common-suffix-queries/

// Solved using Trie
// Time Complexity :- O(n * m)  n = number of words
// Space Complexity :- O(n * m) m = average length of word

class TrieNode {
public:

    int minSize, answer;
    TrieNode* child[26];

    TrieNode ()
    {
        minSize = INT_MAX;
        answer = -1;

        for (int ind = 0; ind < 26; ind++)
            child[ind] = NULL;
    }

    ~TrieNode() 
    {
        for (int ind = 0; ind < 26; ind++)
        {
            if(child[ind]) 
                delete child[ind];        
        } 
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

    int getMinSize()
    {
        return minSize;
    }

    void updateMinSize(int size)
    {
        minSize = size;
    }

    int getAnswer()
    {
        return answer;
    }

    void updateAnswer(int strInd)
    {
        answer = strInd;
    }
};

class Trie {
private:

    TrieNode* root;

public:

    Trie()
    {
        root = new TrieNode();
    }

    ~Trie()
    {
        delete root;
    }
    
    void insert(string &word, int strInd) 
    {    
        int m = word.size();
        TrieNode* node = root;

        if (node->getMinSize() > m)
        {
            node->updateMinSize(m);
            node->updateAnswer(strInd);
        }

        for (auto &it : word)
        {
            if (node->containsKey(it) == NULL)
                node->put(it, new TrieNode());

            node = node->get(it);

            if (node->getMinSize() > m)
            {
                node->updateMinSize(m);
                node->updateAnswer(strInd);
            }
        }
    }
    
    int findLongestPrefix(string &word) 
    {   
        TrieNode* node = root;

        for (auto &it : word)
        {
            if (node->containsKey(it) == NULL)
                break;

            node = node->get(it);
        }

        return node->getAnswer();
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        
        int n = wordsContainer.size();
        Trie trie;

        for (int i = 0; i < n; i++)
        {
            string &word = wordsContainer[i];
            reverse(word.begin(), word.end());
            trie.insert(word, i);
        }

        int m = wordsQuery.size();
        vector<int> ans(m);

        for (int i = 0; i < m; i++)
        {
            string &word = wordsQuery[i];
            reverse(word.begin(), word.end());
            ans[i] = trie.findLongestPrefix(word);
        }

        return ans;
    }
};