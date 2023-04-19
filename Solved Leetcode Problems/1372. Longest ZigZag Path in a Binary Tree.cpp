// Problem Link :- https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/

// Time Complexity :- O(n)
// Space Complexity :- O(n)

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

    int ans = 0;

    void DFS (TreeNode* node, bool flag, int len)
    {
        if (node == NULL)
            return;

        ans = max(ans, len);

        if (flag)
        {
            DFS (node->left, !flag, len + 1);
            DFS (node->right, flag, 1);
        }

        else
        {
            DFS (node->right, !flag, len + 1);
            DFS (node->left, flag, 1);
        }
    }

    int longestZigZag(TreeNode* root) {
        
        DFS (root, true, 0);
        DFS (root, false, 0);

        // Instead of calling DFS for two times, calling any one DFS will also give correct ans

        return ans;
    }
};