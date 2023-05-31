// Problem Link :- https://leetcode.com/problems/binary-tree-preorder-traversal/

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

    void preOrder(TreeNode* root)
    {
        if (root == NULL)
            return;

        ans.emplace_back(root->val);
        
        preOrder(root->left);
        preOrder(root->right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        
        preOrder(root);

        return ans;
    }
};



// Solved by Morris Preorder Traversal Algorithm
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
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> preorder;
        TreeNode* curr = root;

        while (curr)
        {
            if (curr->left == NULL)
            {
                preorder.emplace_back(curr->val);
                curr = curr->right;
            }

            else
            {
                TreeNode* prev = curr->left;

                while (prev->right && prev->right != curr)
                    prev = prev->right;

                if (prev->right == NULL)
                {
                    prev->right = curr;
                    preorder.emplace_back(curr->val);
                    curr = curr->left;
                }

                else if (prev->right == curr)
                {
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }

        return preorder;
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

    vector<int> preorderTraversal(TreeNode* root) {
            
        vector<int> ans;

        if (root == NULL)
            return ans;

        stack<TreeNode*> st;
        st.emplace(root);

        while (!st.empty())
        {
            TreeNode* node = st.top();
            st.pop();

            ans.emplace_back(node->val);

            if (node->right)
                st.emplace(node->right);

            if (node->left)
                st.emplace(node->left);
        }
        
        return ans;
    }
};