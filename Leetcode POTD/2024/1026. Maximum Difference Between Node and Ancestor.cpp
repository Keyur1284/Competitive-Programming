// Problem Link :- https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

// Solved by DFS (Postorder)
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

    int maxDiff = INT_MIN;

    pair<int, int> DFS (TreeNode* node)
    {
        if (node == NULL)
            return {INT_MAX, INT_MIN};

        auto left = DFS(node->left);
        auto right = DFS(node->right);

        int mini = min({node->val, left.first, right.first});
        int maxi = max({node->val, left.second, right.second});

        maxDiff = max(maxDiff, max(abs(maxi - node->val), abs(mini - node->val)));
        
        return {mini, maxi};
    }

    int maxAncestorDiff(TreeNode* root) {
        
        DFS(root);
        return maxDiff;
    }
};



// Solved by DFS (Preorder)
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:

    int maxDiff = INT_MIN;

    void DFS (TreeNode* node, int mini, int maxi)
    {
        if (node == NULL)
            return;

        maxDiff = max(maxDiff, max(abs(maxi - node->val), abs(mini - node->val)));

        mini = min(mini, node->val);
        maxi = max(maxi, node->val);

        DFS(node->left, mini, maxi);
        DFS(node->right, mini, maxi);
    }

    int maxAncestorDiff(TreeNode* root) {
        
        DFS(root, root->val, root->val);
        return maxDiff;
    }
};