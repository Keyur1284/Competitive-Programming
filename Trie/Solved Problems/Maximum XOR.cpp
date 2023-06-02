// Problem Link :- https://www.codingninjas.com/codestudio/problems/maximum-xor_973113

// Solved by Trie Data Structure
// Time Complexity :- O(32*N) + O(32*M)
// Space Complexity :- O(32*N)

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

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) 
{
    Trie* obj = new Trie();

    for (auto &it : arr1)
    {
        obj->insert(it);
    }  

    int ans = 0;

    for (auto &it : arr2)
    {
        int res = obj->findMaxXor(it);
        ans = max(ans, res);
    }

    return ans;
}