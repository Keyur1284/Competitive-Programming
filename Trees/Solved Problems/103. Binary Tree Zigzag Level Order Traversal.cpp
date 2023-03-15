// Problem Link :- https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    
    void DFS(TreeNode* root, int level, vector<vector<int>>& ans)
    {
        if (root == NULL)
            return;
        
        if (level == ans.size())
            ans.emplace_back(vector<int>());
        
        if (level % 2 == 0)
            ans[level].emplace_back(root->val);
        else
            ans[level].emplace(ans[level].begin(), root->val);
        
        DFS(root->left, level + 1, ans);
        DFS(root->right, level + 1, ans);
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        
        DFS(root, 0, ans);
        
        return ans;
    }
};


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
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        
        if (root == NULL)
            return ans;
        
        queue<TreeNode*> q;
        q.emplace(root);
        
        int level = 0;
        
        while (!q.empty())
        {
            int size = q.size();
            vector<int> temp;
            
            for (int i = 0; i < size; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                
                if (level % 2 == 0)
                    temp.emplace_back(node->val);
                
                else
                    temp.emplace(temp.begin(), node->val);
                
                if (node->left != NULL)
                    q.emplace(node->left);
                
                if (node->right != NULL)
                    q.emplace(node->right);
            }
            
            ans.push_back(temp);
            level++;
        }
        
        return ans;
    }
};


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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        queue <TreeNode *> q;
        vector<vector<int>> ans;

        if (root == NULL)
            return ans;

        q.emplace(root);
        int flag = 0;

        while (!q.empty())
        {
            vector <int> temp;
            int k = q.size();

            for (int i = 1; i <= k; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                temp.emplace_back(node->val);

                if (node->left != NULL)
                    q.emplace(node->left);

                if (node->right != NULL)
                    q.emplace(node->right);
            }

            if (flag)
            {
                reverse (temp.begin(), temp.end());
            }

            ans.emplace_back(temp);
            flag = !flag;
        }
        
        return ans;
    }
};