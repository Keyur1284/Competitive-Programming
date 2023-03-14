// Problem Link :- https://leetcode.com/problems/sum-root-to-leaf-numbers/

// Time Complexity :- O(n)
// Space Complexity :- O(n)

// Solved by BFS

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

    int ans = 0;

    void BFS (TreeNode* root)
    {
        queue<pair<TreeNode* , int>> q;
        q.emplace(root, 0);

        while (!q.empty())
        {
            TreeNode* node = q.front().first;
            int sum = q.front().second;
            q.pop();

            sum = sum * 10 + node->val;

            if (node->left==NULL && node->right==NULL)
            {
                ans += sum;
                continue;
            }

            if (node->left)
                q.emplace(node->left, sum);

            if (node->right)
                q.emplace(node->right, sum);
        }
    }

    int sumNumbers(TreeNode* root) {
                
        BFS(root);

        return ans;
    }
};


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

    void DFS (TreeNode* node, int sum, int &ans)
    {
        if (node == NULL)
            return;

        sum = sum * 10 + node->val;

        if (node->left == NULL && node->right == NULL)
        {
            ans += sum;
            cout << ans << " " << sum << endl;
            return;
        }

        DFS (node->left, sum, ans);
        DFS (node->right, sum, ans);
    }

    int sumNumbers(TreeNode* root) {
        
        int ans = 0;
        
        DFS(root, 0, ans);

        return ans;
    }
};