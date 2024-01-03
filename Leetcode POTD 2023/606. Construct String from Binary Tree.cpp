// Problem Link :- https://leetcode.com/problems/construct-string-from-binary-tree/

// Solved by DFS
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
    
    void DFS (TreeNode* node, string &s)
    {
        if (node == NULL)
            return;

        s += to_string(node->val);

        if (node->left || node->right) 
        {
            s += '(';
            DFS (node->left, s);
            s += ')';
        }

        if (node->right) 
        {
            s += '(';
            DFS (node->right, s);
            s += ')';
        }
    }

    string tree2str(TreeNode* root) {
        
        string ans = "";
        DFS (root, ans);

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

    string tree2str(TreeNode* root) {
        
        if (root == NULL) 
            return "";

        string ans = to_string(root->val);

        if (root->left || root->right) 
        {
            ans += "(" + tree2str(root->left) + ")";
        }

        if (root->right) 
        {
            ans += "(" + tree2str(root->right) + ")";
        }
        
        return ans;
    }
};