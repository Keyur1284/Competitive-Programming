// Problem Link :- https://leetcode.com/problems/implement-trie-prefix-tree/

// Insert
// Time Complexity :- O(N)
// Space Complexity :- O(N)

// Search and Prefix
// Time Complexity :- O(N)
// Space Complexity :- O(1)


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

    Trie() {
        
        root = new TrieNode();
    }
    
    void insert(string word) {
        
        TrieNode* node = root;

        for (auto &it : word)
        {
            if (node->containsKey(it) == NULL)
                node->put(it, new TrieNode());

            node = node->get(it);
        }

        node->setEnd();
    }
    
    bool search(string word) {
        
        TrieNode* node = root;

        for (auto &it : word)
        {
            if (node->containsKey(it) == NULL)
                return false;

            node = node->get(it);
        }

        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        
        TrieNode* node = root;

        for (auto &it : prefix)
        {
            if (node->containsKey(it) == NULL)
                return false;

            node = node->get(it);
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */