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

    void DFS (TreeNode* root, unsigned long long depth, unsigned long long index, unsigned long long &ans, unordered_map<unsigned long long, unsigned long long> &start)
    {
        if (root == NULL)
            return;

        if (start.find(depth) == start.end())
            start[depth] = index;

        ans = max(ans, index - start[depth] + 1);

        DFS (root->left, depth + 1, 2 * index + 1, ans, start);
        DFS (root->right, depth + 1, 2 * index + 2, ans, start);
    }

    int widthOfBinaryTree(TreeNode* root) {

        unordered_map<unsigned long long, unsigned long long> start;
        unsigned long long ans = 0;

        DFS (root, 0, 0, ans, start);
        
        return ans;
    }
};