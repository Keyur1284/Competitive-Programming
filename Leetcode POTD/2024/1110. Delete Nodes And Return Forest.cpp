// Problem Link :- https://leetcode.com/problems/delete-nodes-and-return-forest/

// Sovled using DFS
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

    void markNodesToDelete(TreeNode* node, unordered_set<int> &delVals)
    {
        if (node == NULL)
            return;

        if (delVals.count(node->val))
            node->val = -1;

        markNodesToDelete(node->left, delVals);
        markNodesToDelete(node->right, delVals);
    }

    void deleteMarkedNodes(TreeNode* node, TreeNode* parent, vector<TreeNode*> &ans)
    {
        if (node == NULL)
            return;

        deleteMarkedNodes(node->left, node, ans);
        deleteMarkedNodes(node->right, node, ans);

        if (parent && parent->val == -1 && node->val != -1)
            ans.emplace_back(node);

        if (node->left && node->left->val == -1)
            node->left = NULL;

        if (node->right && node->right->val == -1)
            node->right = NULL;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        unordered_set<int> delVals(to_delete.begin(), to_delete.end());
        vector<TreeNode*> ans;
        
        if (!delVals.count(root->val))
            ans.emplace_back(root);
        
        markNodesToDelete(root, delVals);
        deleteMarkedNodes(root, NULL, ans);
        return ans;
    }
};



// Solved by Post Order Traversal
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:

    TreeNode* processNode(TreeNode* node, unordered_set<int>& toDeleteSet, vector<TreeNode*>& forest) {
        
        if (node == NULL)
            return node;

        node->left = processNode(node->left, toDeleteSet, forest);
        node->right = processNode(node->right, toDeleteSet, forest);

        if (toDeleteSet.count(node->val)) 
        {
            if (node->left) 
                forest.emplace_back(node->left);
            
            if (node->right)
                forest.emplace_back(node->right);
            
            delete node;
            return NULL;
        }

        return node;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        unordered_set<int> toDeleteSet(to_delete.begin(), to_delete.end());
        vector<TreeNode*> forest;

        root = processNode(root, toDeleteSet, forest);

        if (root)
            forest.emplace_back(root);

        return forest;
    }
};



// Sovled by BFS
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {

        unordered_set<int> toDeleteSet(to_delete.begin(), to_delete.end());
        vector<TreeNode*> forest;

        queue<TreeNode*> nodesQueue;
        nodesQueue.emplace(root);

        while (!nodesQueue.empty()) 
        {
            TreeNode* currentNode = nodesQueue.front();
            nodesQueue.pop();

            if (currentNode->left) 
            {
                nodesQueue.emplace(currentNode->left);

                if (toDeleteSet.count(currentNode->left->val))
                    currentNode->left = NULL;
            }

            if (currentNode->right) 
            {
                nodesQueue.emplace(currentNode->right);

                if (toDeleteSet.count(currentNode->right->val))
                    currentNode->right = NULL;
            }

            if (toDeleteSet.count(currentNode->val)) 
            {
                if (currentNode->left)
                    forest.emplace_back(currentNode->left);
                
                if (currentNode->right) 
                    forest.emplace_back(currentNode->right);
            }
        }

        if (!toDeleteSet.count(root->val))
            forest.emplace_back(root);

        return forest;
    }
};