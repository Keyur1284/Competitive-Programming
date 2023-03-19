// Problem Link :- https://leetcode.com/problems/design-add-and-search-words-data-structure/

// Time Complexity :- O(n)
// Space Complexity :- O(n)

class TrieNode {
public:
    TrieNode* children[26];
    bool isWordCompleted;

    TrieNode() {
        memset(children, 0, sizeof(children));
        isWordCompleted = false;
    }
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* newRoot = root;
        for (char ch : word) {
            int alphabetIndex = ch - 'a';
            if (newRoot -> children[alphabetIndex] == NULL) {
                newRoot -> children[alphabetIndex] = new TrieNode();
            }
            newRoot = newRoot -> children[alphabetIndex];
        }
        newRoot -> isWordCompleted = true;
    }
    
    bool searchHelper(string word, int index, TrieNode* newRoot) {
        if (index == word.length())
            return newRoot -> isWordCompleted;
        char ch = word[index];
        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (newRoot -> children[i] != NULL && searchHelper(word, index + 1, newRoot -> children[i])) {
                    return true;
                }
            }
            return false;
        }
        else {
            if (newRoot -> children[ch - 'a'] == NULL) {
                return false;
            }
            return (searchHelper(word, index + 1, newRoot -> children[ch - 'a']));
        }
    }

    bool search(string word) {
        return searchHelper(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */