// Problem Link :- https://www.codingninjas.com/codestudio/problems/count-distinct-substrings_985292

// Solved by Trie Data Structure
// Time Complexity :- O(N^2)
// Space Complexity :- O(N^2)

class TrieNode {

    public:

    vector<TrieNode*> child;

    TrieNode ()
    {
        child.assign(26, NULL);
    }
};

TrieNode *root;
int count;

void insert (string &word)
{
    TrieNode *node = root;

    for (auto &it : word)
    {
        int index = it - 'a';

        if (node->child[index] == NULL)
        {
            node->child[index] = new TrieNode();
            count++;
        }

        node = node->child[index];
    }
}

int countDistinctSubstrings(string &s)
{
    root = new TrieNode();
    count = 1;

    int len = s.length();

    for (int i = 0; i < len; i++)
    {
        string word = s.substr(i);
        insert(word);
    }

    return count;
}


// Solution by using concepts of OOPs

class TrieNode {

    public:

    vector<TrieNode*> child;

    TrieNode ()
    {
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
};

int count;

class Trie {

    public:
    
    TrieNode *root;

    Trie() {
        
        root = new TrieNode();
    }

    void insert (string &word)
    {
        TrieNode *node = root;

        for (auto &it : word)
        {
            if (node->containsKey(it) == NULL)
            {
                node->put(it, new TrieNode());
                count++;
            }

            node = node->get(it);
        }
    }

};


int countDistinctSubstrings(string &s)
{
    Trie obj;
    count = 1;

    int len = s.length();

    for (int i = 0; i < len; i++)
    {
        string word = s.substr(i);
        obj.insert(word);
    }

    return count;
}