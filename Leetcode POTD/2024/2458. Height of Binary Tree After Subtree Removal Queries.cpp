// Problem Link :- https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/

// Solved by DFS
// Time Complexity :- O(n + q)
// Space Complexity :- O(n)

class Solution {
public:

    int currentMaxHeight = 0;
    unordered_map<int, int> maxHeightAfterRemoval;

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        
        traverseLeftToRight(root, 0);
        currentMaxHeight = 0;
        traverseRightToLeft(root, 0);

        int queryCount = queries.size();
        vector<int> queryResults(queryCount);
        
        for (int i = 0; i < queryCount; i++) 
        {
            queryResults[i] = maxHeightAfterRemoval[queries[i]];
        }

        return queryResults;
    }

private:

    void traverseLeftToRight(TreeNode* node, int currentHeight) {
        
        if (node == nullptr) 
            return;

        maxHeightAfterRemoval[node->val] = currentMaxHeight;
        currentMaxHeight = max(currentMaxHeight, currentHeight);
        traverseLeftToRight(node->left, currentHeight + 1);
        traverseLeftToRight(node->right, currentHeight + 1);
    }

    void traverseRightToLeft(TreeNode* node, int currentHeight) {
        
        if (node == nullptr) 
            return;

        maxHeightAfterRemoval[node->val] = max(maxHeightAfterRemoval[node->val], currentMaxHeight);
        currentMaxHeight = max(currentHeight, currentMaxHeight);
        traverseRightToLeft(node->right, currentHeight + 1);
        traverseRightToLeft(node->left, currentHeight + 1);
    }
};



class Solution {
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        
        unordered_map<int, int> resultMap;
        unordered_map<TreeNode*, int> heightCache;

        dfs(root, 0, 0, resultMap, heightCache);

        vector<int> result(queries.size());
        
        for (int i = 0; i < queries.size(); i++) 
        {
            result[i] = resultMap[queries[i]];
        }
        
        return result;
    }

private:

    int height(TreeNode* node, unordered_map<TreeNode*, int>& heightCache) {
        
        if (node == nullptr)
            return -1;

        if (heightCache.count(node))
            return heightCache[node];

        int h = 1 + max(height(node->left, heightCache), height(node->right, heightCache));
        
        return heightCache[node] = h;
    }

    void dfs(TreeNode* node, int depth, int maxVal, unordered_map<int, int>& resultMap, unordered_map<TreeNode*, int>& heightCache) {
        
        if (node == nullptr)
            return;

        resultMap[node->val] = maxVal;

        dfs(node->left, depth + 1, max(maxVal, depth + 1 + height(node->right, heightCache)), resultMap, heightCache);
        dfs(node->right, depth + 1, max(maxVal, depth + 1 + height(node->left, heightCache)), resultMap, heightCache);
    }
};