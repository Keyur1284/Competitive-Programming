// Problem Link :- https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/

// Solved using unordered_set
// Time Complexity :- O(n * m)  n = no. of strings
// Space Complexity :- O(n * m) m = avg length of string

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
        unordered_set<string> st;

        for (auto &it : arr1)
        {
            string s = to_string(it);
            int m = s.length();

            for (int i = 1; i <= m; i++)
            {
                string t = s.substr(0, i);
                st.emplace(t);
            }
        }

        int longestPrefix = 0;

        for (auto &it : arr2)
        {
            string s = to_string(it);
            int m = s.length();

            for (int i = 1; i <= m; i++)
            {
                string t = s.substr(0, i);
                
                if (st.count(t))
                    longestPrefix = max(longestPrefix, i);
            }
        }

        return longestPrefix;
    }
};



class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
        unordered_set<int> st;

        for (auto it : arr1)
        {
            while (it > 0)
            {
                st.emplace(it);
                it /= 10;
            }
        }

        int longestPrefix = 0;

        for (auto it : arr2)
        {
            while (it > 0)
            {
                if (st.count(it))
                    longestPrefix = max(longestPrefix, it);

                it /= 10;
            }
        }

        return longestPrefix ? to_string(longestPrefix).length() : 0;
    }
};



// Solved using Trie
// Time Complexity :- O(n * m)  n = no. of strings
// Space Complexity :- O(n * m) m = avg length of string

class TrieNode {
public:

    vector<TrieNode*> child;

    TrieNode()
    {
        child.assign(10, NULL);
    } 

    void put (char k, TrieNode* node)
    {
        int dig = k - '0';
        child[dig] = node;
    }

    bool containsKey (char k)
    {
        int dig = k - '0';
        return (child[dig] != NULL);
    }

    TrieNode* get (char k)
    {
        int dig = k - '0';
        return child[dig];
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

    void insert (int num)
    {
        TrieNode* node = root;
        string s = to_string(num);

        for (auto &k : s)
        {
            if (!node->containsKey(k))
                node->put(k, new TrieNode());

            node = node->get(k);
        }
    }

    int findPrefLen (int num)
    {
        TrieNode* node = root;
        string s = to_string(num);
        int len = 0;

        for (auto &k : s)
        {
            if (!node->containsKey(k))
                break;

            node = node->get(k);
            len++;
        }

        return len;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
        Trie trie;

        for (auto &num : arr1)
            trie.insert(num);

        int longestPrefix = 0;

        for (auto &num : arr2)
        {
            int prefLen = trie.findPrefLen(num);
            longestPrefix = max(longestPrefix, prefLen);
        }

        return longestPrefix;
    }
};