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

    bool containsKey (int num)
    {
        return (child[num] != NULL);
    }

    void put (int num, TrieNode* node)
    {
        child[num] = node;
    }

    TrieNode* get (int num)
    {
        return child[num];
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

            if (node->containsKey(bit) == NULL)
                node->put(bit, new TrieNode());

            node = node->get(bit);
        }
    }

    int findMaxXor (int num)
    {
        int maxi = 0;
        TrieNode *node = root;

        for (int pos = 31; pos >= 0; pos--)
        {
            int bit = ((num >> pos) & 1);

            if (node->containsKey(1 ^ bit))
            {
                maxi |= (1 << pos);
                node = node->get(1 ^ bit);
            }

            else
                node = node->get(bit);
        }

        return maxi;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        
        Trie obj;

        for (auto &it : nums)
        {
            obj.insert(it);
        }  

        int ans = 0;

        for (auto &it : nums)
        {
            int res = obj.findMaxXor(it);
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

    bool containsKey (int num)
    {
        return (child[num] != NULL);
    }

    void put (int num, TrieNode* node)
    {
        child[num] = node;
    }

    TrieNode* get (int num)
    {
        return child[num];
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
        bitset<32> bs(num);

        for (int pos = 31; pos >= 0; pos--)
        {
            int val = bs[pos];

            if (node->containsKey(val) == NULL)
                node->put(val, new TrieNode());

            node = node->get(val);
        }
    }

    int findMaxXor (int num)
    {
        TrieNode* node = root;
        int maxi = 0;
        bitset<32> bs(num);

        for (int pos = 31; pos >= 0; pos--)
        {
            int bit = bs[pos];

            if (node->containsKey(1 ^ bit))
            {
                maxi |= (1 << pos);
                node = node->get(1 ^ bit);
            }

            else
                node = node->get(bit);
        }

        return maxi;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        
        Trie obj;

        for (auto &it : nums)
        {
            obj.insert(it);
        }  

        int ans = 0;

        for (auto &it : nums)
        {
            int res = obj.findMaxXor(it);
            ans = max(ans, res);
        }

        return ans;
    }
};