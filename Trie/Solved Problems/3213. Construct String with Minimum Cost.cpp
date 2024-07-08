// Problem Link :- https://leetcode.com/problems/construct-string-with-minimum-cost/

// Solved using Trie + DP
// Time Complexity :- O(m * len + n^2)  n = target.length(), m = words.length
// Space Complexity :- O(m * len + n)   len = max length of word in words

class TrieNode {
private:
    
    bool endsWord;
    int cost;
    vector<TrieNode*> childrenNodes;

public:
    
    TrieNode()
    {
        endsWord = false;
        cost = INT_MAX;
        childrenNodes.assign(26, NULL);
    }

    TrieNode* get(char &ch) 
    {
        int index = ch - 'a';
        return childrenNodes[index];
    }

    void put(char &ch, TrieNode* node) 
    {
        int index = ch - 'a';
        childrenNodes[index] = node;
    }

    bool containsKey(char &ch) 
    {
        int index = ch - 'a';
        return (childrenNodes[index] != NULL);
    }

    bool isEndsWord() 
    {
        return endsWord;
    }

    void setEndsWord() 
    {
        endsWord = true;
    }

    int getCost() 
    {
        return cost;
    }

    void setCost(int newCost) 
    {
        cost = min(cost, newCost);
    }
};

class Trie {
public:
    
    TrieNode* root;
    
    Trie() 
    {
        root = new TrieNode();
    }

    void buildTrie(vector<string> &words, vector<int> &costs) 
    {
        int m = words.size();

        for (int i = 0; i < m; i++) 
        {
            TrieNode* node = root;

            for (auto &ch : words[i]) 
            {
                if (!node->containsKey(ch))
                    node->put(ch, new TrieNode());
                
                node = node->get(ch);
            }

            node->setEndsWord();
            node->setCost(costs[i]);
        }
    }
};

class Solution {
public:

    int solve(int currIndex, int &n, string& target, vector<int>& dp, Trie &trie) {
        
        if (currIndex >= n)
            return 0;
        
        if (dp[currIndex] != -1) 
            return dp[currIndex];

        int ans = INT_MAX;

        TrieNode* currNode = trie.root;
        
        for (int i = currIndex; i < n; i++) 
        {
            char nextChar = target[i];
            
            if (!currNode->containsKey(nextChar))
                break;
            
            currNode = currNode->get(nextChar);

            if (currNode->isEndsWord()) 
            {
                int localAns = solve(i + 1, n, target, dp, trie);

                if (localAns != INT_MAX) 
                {
                    localAns += currNode->getCost();
                    ans = min(ans, localAns);
                }
            }
        }

        dp[currIndex] = ans;
        return ans;
    }
    
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        
        Trie trie;
        trie.buildTrie(words, costs);

        int n = target.length();
        vector<int> dp(n, -1);

        int ans = solve(0, n, target, dp, trie);
        return ans == INT_MAX ? -1 : ans;
    }
};