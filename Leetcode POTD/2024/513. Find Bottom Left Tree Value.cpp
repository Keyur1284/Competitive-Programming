// Problem Link :- https://leetcode.com/problems/find-bottom-left-tree-value/

// Solved by Level Order Traversal
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
    int findBottomLeftValue(TreeNode* root) {
        
        queue<TreeNode*> BFS;
        BFS.emplace(root);
        int ans;

        while (!BFS.empty())
        {
            int size = BFS.size();

            for (int i = 1; i <= size; i++)
            {
                auto node = BFS.front();
                BFS.pop();

                if (i == 1)
                    ans = node->val;

                if (node->left)
                    BFS.emplace(node->left);

                if (node->right)
                    BFS.emplace(node->right);
            }
        }

        return ans;
    }
};



// Solved by DFS
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        
        int ans, maxDepth = -1;

        function<void(TreeNode*, int)> DFS = [&](TreeNode* node, int depth) -> void {

            if (node == NULL)
                return;

            if (depth > maxDepth)
            {
                maxDepth = depth;
                ans = node->val;
            }

            DFS(node->left, depth + 1);
            DFS(node->right, depth + 1);
        };

        DFS(root, 0);

        return ans;
    }
};



// Solved by BFS
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        
        queue<TreeNode*> BFS;
        BFS.emplace(root);
        int ans;

        while (!BFS.empty())
        {
            auto node = BFS.front();
            BFS.pop();

            ans = node->val;

            if (node->right)
                BFS.emplace(node->right);

            if (node->left)
                BFS.emplace(node->left);
        }

        return ans;
    }
};