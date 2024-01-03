// Problem Link :- https://leetcode.com/problems/find-largest-value-in-each-tree-row/

// Solved by BFS
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
    vector<int> largestValues(TreeNode* root) {
        
        if (root == NULL)
            return {};

        vector<int> largest;
        queue<TreeNode*> BFS;
        BFS.emplace(root);

        while (!BFS.empty())
        {
            int size = BFS.size(), maxi = INT_MIN;

            while (size--)
            {
                TreeNode* node = BFS.front();
                BFS.pop();

                maxi = max(maxi, node->val);

                if (node->left)
                    BFS.emplace(node->left);

                if (node->right)
                    BFS.emplace(node->right);
            }

            largest.emplace_back(maxi);
        }

        return largest;
    }
};



// Solved by DFS
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    
    void DFS(TreeNode* root, int level, vector<int>& largest)
    {
        if (root == NULL)
            return;

        if (level == largest.size())
            largest.emplace_back(root->val);
        
        else
            largest[level] = max(largest[level], root->val);

        DFS(root->left, level + 1, largest);
        DFS(root->right, level + 1, largest);
    }
    
    vector<int> largestValues(TreeNode* root) {
        
        if (root == NULL)
            return {};

        vector<int> largest;
        DFS(root, 0, largest);

        return largest;
    }

};