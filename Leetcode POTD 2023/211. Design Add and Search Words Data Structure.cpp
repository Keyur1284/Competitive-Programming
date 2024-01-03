// Problem Link :- https://leetcode.com/problems/design-add-and-search-words-data-structure/

// Time Complexity :- O(n*m)
// Space Complexity :- O(n*m)

class TrieNode {
public:

    bool isEnd;
    vector<TrieNode*> children;

    TrieNode()
    {
        isEnd = false;
        children.assign(26, 0);
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

            if (node->children[index] == NULL)
                node->children[index] = new TrieNode();

            node = node->children[index];
        }
        
        node->isEnd = true;
    }

    bool searchHelper (string word, TrieNode* node)
    {
        int n = word.size();

        for (int i = 0; i < n; i++)
        {
            if (word[i] == '.')
            {
                for (auto &it : node->children)
                {
                    if (it && searchHelper(word.substr(i + 1), it))
                        return true;
                }

                return false;
            }

            int index = word[i] - 'a';

            if (node->children[index] == NULL)
                return false;

            node = node->children[index];
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


// Solved by using vector 

// Time Complexity :- O(n*m)
// Space Complexity :- O(n*m)

class WordDictionary {
public:

    vector<string> words;

    WordDictionary() {
        
    }
    
    void addWord(string word) {
        
        words.emplace_back(word);
    }
    
    bool search(string word) {

        int len = word.size(), n = words.size(), count = 0;

        for (int i = 0; i < n; i++)
        {
            if (words[i].size() == len)
            {
                for (int j = 0; j < len; j++)
                {
                    if (words[i][j] == word[j] || word[j] == '.')
                        count++;

                    else
                    {
                        count = 0;
                        break;
                    }
                }

                if (count == len)
                    return true;
            }
        }

        return false;  
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */