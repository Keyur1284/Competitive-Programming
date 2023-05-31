// Problem Link :- https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

// Time Complexity :- O(N)
// Space Complexity :- O(N)

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

    TreeNode* prev = NULL;

    void flatten(TreeNode* root) {
        
        if (root == NULL)
            return;

        flatten (root->right);
        flatten (root->left);

        root->right = prev;
        root->left = NULL;
        prev = root;
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
    void flatten(TreeNode* root) {
        
        if (root == NULL)
            return;

        stack<TreeNode*> st;
        st.emplace(root);

        while (!st.empty())
        {
            TreeNode* node = st.top();
            st.pop();

            if (node->right)
                st.emplace(node->right);

            if (node->left)
                st.emplace(node->left);

            if (!st.empty())
                node->right = st.top();

            node->left = NULL;
        }
    }
};



// Solved by Morris Traversal Algorithm Intuition
// Time Complexity :- O(N)
// Space Complexity :- O(1)

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
    void flatten(TreeNode* root) {
        
        TreeNode* curr = root;

        while (curr)
        {
            if (curr->left)
            {
                TreeNode* prev = curr->left;

                while (prev->right)
                    prev = prev->right;

                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }

            curr = curr->right;
        }
    }
};