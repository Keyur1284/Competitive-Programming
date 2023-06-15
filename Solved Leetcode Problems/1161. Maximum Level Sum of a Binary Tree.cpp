// Problem Link :- https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

// Solved by Level Order Traversal  (BFS)
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
    int maxLevelSum(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.emplace(root);
        int maxi = INT_MIN, level = 1, ans = 1;

        while (!q.empty())
        {
            int size = q.size(), sum = 0;
                
            while(size--)
            {
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;

                if (node->left)
                    q.emplace(node->left);

                if (node->right)
                    q.emplace(node->right);
            }

            if (sum > maxi)
            {
                maxi = sum;
                ans = level;
            }

            level++;
        }

        return ans;
    }
};



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
    vector<int> levelWiseSum = {-1};

    void DFS (TreeNode* node, int level)
    {
        if (node == NULL)
            return;

        if (level == levelWiseSum.size())
            levelWiseSum.emplace_back(node->val);

        else
            levelWiseSum[level] += node->val;

        DFS (node->left, level + 1);
        DFS (node->right, level + 1);
    }

    int maxLevelSum(TreeNode* root) {
        
        DFS (root, 1);

        int maxi = INT_MIN, ans = -1;

        for (int level = 1; level < levelWiseSum.size(); level++)
        {
            if (levelWiseSum[level] > maxi)
            {
                maxi = levelWiseSum[level];
                ans = level;
            }
        }

        return ans;
    }
};