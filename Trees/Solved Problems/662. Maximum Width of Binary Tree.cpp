// Problem Link :- https://leetcode.com/problems/maximum-width-of-binary-tree/

// Solved by BFS

// Time Complexity: O(n)
// Space Complexity: O(n)

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
    int widthOfBinaryTree(TreeNode* root) {
        
        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.emplace(root, 0);

        while (!q.empty())
        {
            int size = q.size(), start, end;
            int min_index = q.front().second;

            for (int i = 1; i <= size; i++)
            {
                TreeNode* node = q.front().first;
                int index = q.front().second - min_index;
                q.pop();

                if (i == 1)
                    start = index;

                if (i == size)
                    end = index;

                if (node->left)
                    q.emplace(node->left, 2LL * index + 1);

                if (node->right)
                    q.emplace(node->right, 2LL * index + 2);
            }

            ans = max (ans, end - start + 1);
        }

        return ans;
    }
};


// Solved by DFS

// Time Complexity: O(n)
// Space Complexity: O(n)

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

    unordered_map <int, int> mp;
    int maxi = 0;

    void DFS (TreeNode* node, int level, int index)
    {
        if (node == NULL)
            return;

        if (mp.find(level) == mp.end())
            mp[level] = index;

        index = index - mp[level];

        maxi = max(maxi, index + 1);

        DFS (node->left, level + 1, 2LL * index + 1);
        DFS (node->right, level + 1, 2LL * index + 2);
    }

    int widthOfBinaryTree(TreeNode* root) {
        
        DFS(root, 0, 0);

        return maxi;
    }
};