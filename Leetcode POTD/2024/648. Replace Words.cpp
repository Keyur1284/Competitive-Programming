// Problem Link :- https://leetcode.com/problems/replace-words/

// Solved using stringstream and unordered_set
// Time Complexity :- O(d * w + s * w^2)  d = no. of words in dictionary, s = no. of words in sentence
// Space Complexity :- O(d * w + s * w)  w = average length of each word

class Solution {
public:
    string shortestRoot(string &word, unordered_set<string> &dictSet)
    {
        string root;

        for (auto &ch : word)
        {
            root += ch;

            if (dictSet.count(root))
                break;
        }

        return root;
    }

    string replaceWords(vector<string> &dictionary, string sentence)
    {

        unordered_set<string> dictSet(dictionary.begin(), dictionary.end());
        stringstream ss(sentence);
        string word, newSentence;

        while (getline(ss, word, ' '))
            newSentence += shortestRoot(word, dictSet) + " ";

        newSentence.pop_back();

        return newSentence;
    }
};



// Solved using stringstream and Trie
// Time Complexity :- O(d * w + s * w)  d = no. of words in dictionary, s = no. of words in sentence
// Space Complexity :- O(d * w)  w = average length of each word

class TrieNode {
public:

    bool flag;
    vector<TrieNode*> child;

    TrieNode ()
    {
        flag = false;
        child.assign(26, NULL);
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
private:

    TrieNode* root;

public:

    Trie() 
    {
        
        root = new TrieNode();
    }
    
    void insert(string word) {
        
        TrieNode* node = root;

        for (auto &it : word)
        {
            if (!node->containsKey(it))
                node->put(it, new TrieNode());

            node = node->get(it);
        }

        node->setEnd();
    }

    string shortestRoot(string &word)
    {
        TrieNode* node = root;
        string root;

        for (auto &ch : word)
        {
            if (!node->containsKey(ch) || node->isEnd())
                break;

            root += ch;
            node = node->get(ch);
        }

        return node->isEnd() ? root : word;
    }
};

class Solution {
public:

    string replaceWords(vector<string> &dictionary, string sentence)
    {
        Trie trie;

        for (auto &word : dictionary)
            trie.insert(word);

        stringstream ss(sentence);
        string word, newSentence;

        while (getline(ss, word, ' '))
            newSentence += trie.shortestRoot(word) + " ";

        newSentence.pop_back();

        return newSentence;
    }
};