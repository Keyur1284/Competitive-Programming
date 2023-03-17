// Problem Link :- https://leetcode.com/problems/implement-trie-prefix-tree/

// Time Complexity :- O(n), n -> length of the string;
// Space Complexity :- O(n)

class TrieNode {
public:

    bool isEnd;
    vector<TrieNode*> children;

    TrieNode ()
    {
        isEnd = false;
        children.assign(26, 0);
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

            if (node->children[index] == NULL)
                node->children[index] = new TrieNode();

            node = node->children[index];
        }

        node->isEnd = true;
    }
    
    bool search(string word) {
        
        TrieNode* node = root;

        for (auto &it : word)
        {
            int index = it - 'a';

            if (node->children[index] == NULL)
                return false;

            node = node->children[index];
        }

        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        
        TrieNode* node = root;

        for (auto &it : prefix)
        {
            int index = it - 'a';

            if (node->children[index] == NULL)
                return false;

            node = node->children[index];
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