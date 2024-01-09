// Problem Link :- https://leetcode.com/problems/leaf-similar-trees/

// Solved by DFS
// Time Complexity :- O(n + m)
// Space Complexity :- O(n + m)

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

    vector<int> leafNodes1, leafNodes2;

    void DFS (TreeNode* node, vector<int> &leafNodes)
    {
        if (node == NULL)
            return;

        DFS (node->left, leafNodes);

        if (node->left == NULL && node->right == NULL)
            leafNodes.emplace_back(node->val);

        DFS (node->right, leafNodes);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        DFS (root1, leafNodes1);
        DFS (root2, leafNodes2);

        return (leafNodes1 == leafNodes2);
    }
};