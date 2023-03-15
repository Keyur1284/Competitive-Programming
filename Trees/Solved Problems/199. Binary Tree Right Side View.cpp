// Problem Link :- https://leetcode.com/problems/binary-tree-right-side-view/

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

    void DFS (TreeNode* node, int level, vector<int> &ans)
    {
        if (node == NULL)
            return;

        if (level == ans.size())
            ans.emplace_back(node->val);

        DFS (node->right, level + 1, ans);
        DFS (node->left, level + 1, ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> ans;

        DFS (root, 0, ans);

        return ans;
    }
};


// Solved by BFS

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> ans;
        
        if (root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.emplace(root);

        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                if (i == n - 1)
                    ans.emplace_back(node->val);

                if (node->left != NULL)
                    q.emplace(node->left);

                if (node->right != NULL)
                    q.emplace(node->right);
            }
        }

        return ans;
    }
};
