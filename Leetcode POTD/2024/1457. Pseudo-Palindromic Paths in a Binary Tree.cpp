// Problem Link :- https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/

// Solved by DFS
// Time Complexity :- O(n)
// Space Complexity :- O(h)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        
        int ans = 0;
        vector<int> freq(10, 0);

        auto DFS = [&](auto self, TreeNode* node)
        {
            if (node == NULL)
                return;

            freq[node->val]++;

            if (node->left == NULL && node->right == NULL)
            {
                int odd = 0;

                for (auto &it : freq)
                    odd += (it & 1);

                if (odd <= 1)
                    ans++;
            }

            else
            {
                self(self, node->left);
                self(self, node->right);
            }

            freq[node->val]--;
        };

        DFS(DFS, root);

        return ans;
    }
};



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        
        int ans = 0, mask = 0;

        auto DFS = [&](auto self, TreeNode* node, int mask)
        {
            if (node == NULL)
                return;

            mask ^= (1 << node->val);

            if (node->left == NULL && node->right == NULL)
            {
                bool checkPowerOfTwo = (mask & (mask - 1)) == 0;
                    
                if (checkPowerOfTwo)
                    ans++;
            }

            else
            {
                self(self, node->left, mask);
                self(self, node->right, mask);
            }
        };

        DFS(DFS, root, mask);

        return ans;
    }
};