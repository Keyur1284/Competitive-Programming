// Problem Link :- https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

// Solved by Trie Data Structure
// Time Complexity :- O(32 * N) + O(32 * N)
// Space Complexity :- O(32 * N)

// Solution checking $i^{th}$ bit manually

class TrieNode {

    public:

    vector<TrieNode*> child;

    TrieNode ()
    {
        child.assign(2, NULL);
    }
};

class Trie {

    public:

    TrieNode* root;

    Trie ()
    {
        root = new TrieNode();
    }

    void insert (int num)
    {
        TrieNode* node = root;

        for (int pos = 31; pos >= 0; pos--)
        {
            int bit = ((num >> pos) & 1);

            if (node->child[bit] == NULL)
                node->child[bit] = new TrieNode();

            node = node->child[bit];
        }
    }

    int findMaxXor (int num)
    {
        int maxi = 0;
        TrieNode *node = root;

        for (int pos = 31; pos >= 0; pos--)
        {
            int bit = ((num >> pos) & 1);

            if (node->child[1 ^ bit])
            {
                maxi |= (1 << pos);
                node = node->child[1 ^ bit];
            }

            else
                node = node->child[bit];
        }

        return maxi;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        
        Trie* obj = new Trie();

        for (auto &it : nums)
        {
            obj->insert(it);
        }  

        int ans = 0;

        for (auto &it : nums)
        {
            int res = obj->findMaxXor(it);
            ans = max(ans, res);
        }

        return ans;
    }
};


// Solution using inbuilt bitset in STL 

class TrieNode {

    public:

    vector<TrieNode*> child;

    TrieNode ()
    {
        child.assign(2, NULL);
    }
};

class Trie {

    public:

    TrieNode* root;

    Trie ()
    {
        root = new TrieNode();
    }

    void insert (int num)
    {
        TrieNode* node = root;
        bitset<32> bit(num);

        for (int pos = 31; pos >= 0; pos--)
        {
            if (node->child[bit[pos]] == NULL)
                node->child[bit[pos]] = new TrieNode();

            node = node->child[bit[pos]];
        }
    }

    int findMaxXor (int num)
    {
        int maxi = 0;
        TrieNode *node = root;
        bitset<32> bit(num);

        for (int pos = 31; pos >= 0; pos--)
        {
            if (node->child[1 ^ bit[pos]])
            {
                maxi |= (1 << pos);
                node = node->child[1 ^ bit[pos]];
            }

            else
                node = node->child[bit[pos]];
        }

        return maxi;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        
        Trie* obj = new Trie();

        for (auto &it : nums)
        {
            obj->insert(it);
        }  

        int ans = 0;

        for (auto &it : nums)
        {
            int res = obj->findMaxXor(it);
            ans = max(ans, res);
        }

        return ans;
    }
};