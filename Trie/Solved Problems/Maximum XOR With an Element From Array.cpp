// Problem Link :- https://www.codingninjas.com/codestudio/problems/max-xor-queries_1382020

// Solved by Trie Data Structure
// Time Complexity :- O(Q logQ) + (N logN) + O(32 * Q) + O(32 * N)
// Space Complexity :- O(32 * N)

#include <bits/stdc++.h>

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

bool comp (vector<int> &v1, vector<int> &v2)
{
	return v1[1] < v2[1];
}

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	
	Trie* obj = new Trie();

	int q = queries.size();
	int n = arr.size();
	vector<int> ans(q, -1);

	for (int i = 0; i < q; i++)
	{
		queries[i].emplace_back(i);
	}

	sort (queries.begin(), queries.end(), comp);
	sort (arr.begin(), arr.end());

	int j = 0;

	for (int i = 0; i < q; i++)
	{
		int xorVal = queries[i][0];
		int num = queries[i][1];
		int index = queries[i][2];

		while (j < n && arr[j] <= num)
			obj->insert(arr[j++]);

		if (j > 0)
		{
			ans[index] = obj->findMaxXor(xorVal);
		}
	}

	return ans;
}