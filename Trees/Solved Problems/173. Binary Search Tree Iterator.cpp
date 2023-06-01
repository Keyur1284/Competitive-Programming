// Problem Link :- https://leetcode.com/problems/binary-search-tree-iterator/

// Time Complexity :- O(1)
// Space Complexity :- O(H)     H -> height of BST

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
class BSTIterator {
public:

    stack<TreeNode*> st;

    void pushNodes (TreeNode* root)
    {
        TreeNode* node = root;

        while (node)
        {
            st.emplace(node);
            node = node->left;
        }
    }

    BSTIterator(TreeNode* root) {
        
        pushNodes (root);
    }
    
    int next() {
        
        TreeNode* node = st.top();
        st.pop();

        pushNodes (node->right);

        return node->val;
    }
    
    bool hasNext() {
        
        return (!st.empty());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */