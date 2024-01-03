// Problem Link :- https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

// Time Complexity :- O(n)
// Space Complexity :- O(n)

// Solved by DFS

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

    TreeNode* buildTreeHelper (int start, int end, int &rootIndex, vector<int>& inorder, vector<int>& postorder, unordered_map <int, int> &mp)
    {
        if (start > end)
            return NULL;

        int rootValue = postorder[rootIndex--];
        int pivot = mp[rootValue];

        TreeNode* root = new TreeNode(rootValue);
        root->right = buildTreeHelper (pivot + 1, end, rootIndex, inorder, postorder, mp);
        root->left = buildTreeHelper (start, pivot - 1, rootIndex, inorder, postorder, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        unordered_map <int, int> mp;
        int n = inorder.size();
        int rootIndex = postorder.size() - 1;

        for (int i = 0; i < n; i++)
            mp[inorder[i]] = i;

        return buildTreeHelper (0, n - 1, rootIndex, inorder, postorder, mp);
    }
};


// Solved using Stack

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

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int inIndex = inorder.size() - 1;
        int postIndex = postorder.size() - 1;

        stack<TreeNode*> st;

        TreeNode* root = new TreeNode(postorder[postIndex--]);
        st.emplace(root);

        TreeNode* prev = NULL;

        while (postIndex >= 0)
        {
            while (!st.empty() && st.top()->val == inorder[inIndex])
            {
                prev = st.top();
                st.pop();
                inIndex--;
            }

            TreeNode* node = new TreeNode(postorder[postIndex--]);

            if (prev)
                prev->left = node;

            else if (!st.empty())
            {
                TreeNode* currTop = st.top();
                currTop->right = node;
            }

            st.emplace(node);
            prev = NULL;
        }

        return root;
    }
};
