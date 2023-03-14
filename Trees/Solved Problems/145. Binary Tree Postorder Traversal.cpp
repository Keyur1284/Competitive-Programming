// Problem Link :- https://leetcode.com/problems/binary-tree-postorder-traversal/

// Time Complexity :- O(n)
// Space Complexity :- O(n)

// Solved by Recursive Approach

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

    vector<int> ans;

    void postOrder(TreeNode* root)
    {
        if (root == NULL)
            return;

        postOrder(root->left);
        postOrder(root->right);
        ans.emplace_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        
        postOrder(root);

        return ans;
    }
};


// Solved by Iterative Approach

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

    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> ans;

        if (root == NULL)
            return ans;

        stack<TreeNode*> st1, st2;
        st1.emplace(root);

        while (!st1.empty())
        {
            TreeNode* node = st1.top();
            st1.pop();
            st2.emplace(node);

            if (node->left)
                st1.emplace(node->left);

            if (node->right)
                st1.emplace(node->right);
        }

        while (!st2.empty())
        {
            ans.emplace_back(st2.top()->val);
            st2.pop();
        }

        return ans;
    }
};