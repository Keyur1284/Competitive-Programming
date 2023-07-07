// Problem Link :- https://leetcode.com/problems/maximum-xor-with-an-element-from-array/

// Solved by Trie Data Structure
// Time Complexity :- O(Q * logQ) + (N * logN) + O(32 * Q) + O(32 * N)
// Space Complexity :- O(32 * N)

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
private:

    TrieNode* root;

public:

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

    static bool comp (vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n = nums.size(), q = queries.size();
        vector<int> maxXor(q, -1);

        Trie obj;

        for (int i = 0; i < q; i++)
            queries[i].emplace_back(i);
        
        sort (nums.begin(), nums.end());
        sort (queries.begin(), queries.end(), comp);
        
        int i = 0;

        for (auto &it : queries)
        {   
            int num = it[0], limit = it[1], index = it[2];

            while (i < n && nums[i] <= limit)
                obj.insert(nums[i++]);

            if (i > 0)
            {
                maxXor[index] = obj.findMaxXor(num);
            }
        }

        return maxXor;
    }
};