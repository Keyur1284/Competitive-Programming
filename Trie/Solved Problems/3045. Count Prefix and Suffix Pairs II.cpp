// Problem Link :- https://leetcode.com/problems/count-prefix-and-suffix-pairs-ii/

// Solved using Trie
// Time Complexity :- O(n * m)      n = number of words
// Space Complexity :- O(n * m)     m = maximum length of word

class TrieNode {
private:

    int count;
    unordered_map<int, TrieNode*> child;

public:

    TrieNode()
    {
        count = 0;
    }

    void put (char pre, char suf, TrieNode* node)
    {
        int index = ((pre - 'a' + 1) << 5) + (suf - 'a');
        child[index] = node;
    }

    bool containsKey (char pre, char suf)
    {
        int index = ((pre - 'a' + 1) << 5) + (suf - 'a');
        return (child[index] != 0);
    }

    TrieNode* get (char pre, char suf)
    {
        int index = ((pre - 'a' + 1) << 5) + (suf - 'a');
        return child[index];
    }

    void increaseCount()
    {
        count++;
    }

    int getCount()
    {
        return count;
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

    void insert(string &word, long long &pairCount)
    {
        TrieNode* node = root;
        int n = word.length();

        for (int i = 0; i < n; i++)
        {
            if (!node->containsKey(word[i], word[n - i - 1]))
                node->put(word[i], word[n - i - 1], new TrieNode());

            node = node->get(word[i], word[n - i - 1]);
            pairCount += node->getCount();
        }

        node->increaseCount();
    }
};

class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        
        Trie trie;
        long long pairCount = 0;

        for (auto &word : words)
        {
            trie.insert(word, pairCount);
        }

        return pairCount;
    }
};



// Solved using Z-Algorithm
// Time Complexity :- O(n * m)      n = number of words
// Space Complexity :- O(n)         m = maximum length of word

class Solution {
public:

    vector<int> zAlgo (string &s)
    {
        int n = s.length();
        vector<int> z(n);
        z[0] = n;

        int left = 0, right = 0;

        for (int i = 1; i < n; i++)
        {
            if (right - i > 0)
            {
                z[i] = min(z[i - left], right - i);
            }

            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                z[i]++;

            if (i + z[i] > right)
            {
                left = i;
                right = i + z[i];
            }
        }

        return z;
    }

    long long countPrefixSuffixPairs(vector<string>& words) {
        
        long long pairCount = 0;
        unordered_map<long long, int> freq;
        long long MOD = 1e9 + 7;

        for (auto &word : words)
        {
            int n = word.length();
            auto z = zAlgo(word);
            long long hash = 0, k = 26;

            for (int i = 1; i <= n; i++)
            {
                hash = (hash * k + word[i - 1] - 'a' + 1) % MOD;

                if (z[n - i] == i)
                {
                    if (freq.count(hash))
                        pairCount += freq[hash];
                }
            }

            freq[hash]++;
        }

        return pairCount;
    }
};