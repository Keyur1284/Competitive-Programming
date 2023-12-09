// Problem Link :- https://leetcode.com/problems/binary-tree-inorder-traversal/

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

    void inOrder(TreeNode* root)
    {
        if (root == NULL)
            return;

        inOrder(root->left);
        ans.emplace_back(root->val);
        inOrder(root->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        
        inOrder(root);

        return ans;
    }
};


// Solved by Morris Inorder Traversal Algorithm
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
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> inorder;
        TreeNode* curr = root;

        while (curr)
        {
            if (curr->left == NULL)
            {
                inorder.emplace_back(curr->val);
                curr = curr->right;
            }

            else
            {
                TreeNode* prev = curr->left;

                while (prev->right && prev->right != curr)
                {
                    prev = prev->right;
                }
                    
                if (prev->right == NULL)
                {
                    prev->right = curr;
                    curr = curr->left;
                }

                else if (prev->right == curr)
                {
                    prev->right = NULL;
                    inorder.emplace_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return inorder;
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
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> ans;

        if (root == NULL)
            return ans;

        TreeNode* curr = root;
        stack<TreeNode*> st;
        st.emplace(root);

        while (!st.empty())
        {
            while (curr->left)
            {
                curr = curr->left;
                st.emplace(curr);
            }

            curr = st.top();
            curr->left = NULL;
            st.pop();

            ans.emplace_back(curr->val);

            if (curr->right)
            {
                curr = curr->right;
                st.emplace(curr);
            }
        }

        return ans;
    }
};