// Problem Link :- https://www.interviewbit.com/problems/path-to-given-node/

// Time Complexity :- O(n)
// Space Complexity :- O(n)

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool findPath (TreeNode* root, int target, vector<int> &ans)
{
    if (root == NULL)
        return false;
        
    ans.emplace_back(root->val);
    
    if (ans.back() == target)
        return true;
        
    bool left = findPath(root->left, target, ans);
    bool right = findPath(root->right, target, ans);
    
    if (left || right)
        return true;
        
    ans.pop_back();
    return false;
}
 
vector<int> Solution::solve(TreeNode* A, int B) {
    
    vector<int> ans;
    
    if (A == NULL)
        return ans;
        
    findPath(A, B, ans);
    
    return ans;
}