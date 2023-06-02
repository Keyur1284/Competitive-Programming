// Problem Link :- https://leetcode.com/problems/implement-trie-prefix-tree/

// Insert
// Time Complexity :- O(N)
// Space Complexity :- O(N)

// Search and Prefix
// Time Complexity :- O(N)
// Space Complexity :- O(1)


class TrieNode {
public:

    bool isEnd;
    vector<TrieNode*> child;

    TrieNode ()
    {
        isEnd = false;
        child.assign(26, NULL);
    }
};

class Trie {
public:

    TrieNode* root;

    Trie() {
        
        root = new TrieNode();
    }
    
    void insert(string word) {
        
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
    
    bool search(string word) {
        
        TrieNode* node = root;

        for (auto &it : word)
        {
            int index = it - 'a';

            if (node->child[index] == NULL)
                return false;

            node = node->child[index];
        }

        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        
        TrieNode* node = root;

        for (auto &it : prefix)
        {
            int index = it - 'a';

            if (node->child[index] == NULL)
                return false;

            node = node->child[index];
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