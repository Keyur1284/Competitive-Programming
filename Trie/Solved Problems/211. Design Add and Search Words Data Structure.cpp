// Problem Link :- https://leetcode.com/problems/design-add-and-search-words-data-structure/

// Solved by Trie Data Structure

// AddWord
// Time Complexity :- O(N)
// Space Complexity :- O(N)

// Search
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

class WordDictionary {
public:

    TrieNode* root;

    WordDictionary() {
        
        root = new TrieNode();
    }
    
    void addWord(string word) {

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

    bool searchHelper (string word, TrieNode* node)
    {
        int len = word.length();

        for (int i = 0; i < len; i++)
        {
            if (word[i] == '.')
            {
                for (auto &it : node->child)
                {
                    if (it && searchHelper (word.substr(i + 1), it))
                        return true;
                }

                return false;
            }

            else
            {
                int index = word[i] - 'a';

                if (node->child[index] == NULL)
                    return false;

                node = node->child[index];
            }
        }

        return node->isEnd;
    }
    
    bool search(string word) {
        
        return searchHelper (word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */