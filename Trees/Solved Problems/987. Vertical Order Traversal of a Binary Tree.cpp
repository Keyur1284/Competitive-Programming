// Problem Link :- https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

// Time Complexity :- O(n*logn*logn*logn)
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> ans;
        queue<pair<TreeNode*, pair<int, int>>> q;

        map<int, map<int, multiset<int>>> nodes;
        q.push({root, {0, 0}});

        while (!q.empty())
        {
            TreeNode* node = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();

            nodes[x][y].emplace(node->val);

            if (node->left)
                q.push({node->left, {x - 1, y + 1}});

            if (node->right)
                q.push({node->right, {x + 1, y + 1}});
        }

        for (auto &it : nodes)
        {
            vector<int> col;

            for (auto &it1 : it.second)
            {
                for (auto &it2 : it1.second)
                    col.emplace_back(it2);
            }

            ans.emplace_back(col);
        }
    
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

    void DFS (TreeNode* root, int x, int y, map<int, map<int, multiset<int>>> &nodes)
    {
        if (root == NULL)
            return;

        nodes[x][y].emplace(root->val);

        DFS (root->left, x - 1, y + 1, nodes);
        DFS (root->right, x + 1, y + 1, nodes);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> ans;
        map<int, map<int, multiset<int>>> nodes;
        
        DFS(root, 0, 0, nodes);

        for (auto &it : nodes)
        {
            vector<int> col;

            for (auto &it1 : it.second)
            {
                for (auto &it2 : it1.second)
                    col.emplace_back(it2);
            }

            ans.emplace_back(col);
        }
    
        return ans;
    }
};