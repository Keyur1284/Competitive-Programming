// Problem Link :- https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/

// Solved by DFS + BFS
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:

    string backtrackPath(TreeNode* node, unordered_map<TreeNode*, pair<TreeNode*, string>> &pathTracker) 
    {
        string path;

        while (pathTracker.count(node)) 
        {
            path += pathTracker[node].second;
            node = pathTracker[node].first;
        }

        reverse(path.begin(), path.end());
        
        return path;
    }

    void populateParentMap(TreeNode* node, unordered_map<int, TreeNode*>& parentMap) {
        
        if (node == NULL) 
            return;

        if (node->left) 
        {
            parentMap[node->left->val] = node;
            populateParentMap(node->left, parentMap);
        }

        if (node->right) 
        {
            parentMap[node->right->val] = node;
            populateParentMap(node->right, parentMap);
        }
    }

    TreeNode* findStartNode(TreeNode* node, int startValue) {
        
        if (node == NULL) 
            return NULL;

        if (node->val == startValue) 
            return node;

        TreeNode* left = findStartNode(node->left, startValue);
        
        if (left) 
            return left;
            
        return findStartNode(node->right, startValue);
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {

        unordered_map<int, TreeNode*> parentMap;
        TreeNode* startNode = findStartNode(root, startValue);
        populateParentMap(root, parentMap);

        queue<TreeNode*> q;
        q.push(startNode);
        unordered_set<TreeNode*> visitedNodes;
        unordered_map<TreeNode*, pair<TreeNode*, string>> pathTracker;
        visitedNodes.insert(startNode);

        while (!q.empty()) 
        {
            TreeNode* currentNode = q.front();
            q.pop();

            if (currentNode->val == destValue)
                return backtrackPath(currentNode, pathTracker);

            if (parentMap.count(currentNode->val))
            {
                TreeNode* parentNode = parentMap[currentNode->val];
                
                if (!visitedNodes.count(parentNode)) 
                {
                    q.push(parentNode);
                    pathTracker[parentNode] = {currentNode, "U"};
                    visitedNodes.insert(parentNode);
                }
            }

            if (currentNode->left && !visitedNodes.count(currentNode->left)) 
            {
                q.push(currentNode->left);
                pathTracker[currentNode->left] = {currentNode, "L"};
                visitedNodes.insert(currentNode->left);
            }

            if (currentNode->right && !visitedNodes.count(currentNode->right)) 
            {
                q.push(currentNode->right);
                pathTracker[currentNode->right] = {currentNode, "R"};
                visitedNodes.insert(currentNode->right);
            }
        }

        return "";
    }    
};



// Solved by LCA + DFS
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:

    TreeNode* findLowestCommonAncestor(TreeNode* node, int value1, int value2) {
        
        if (node == NULL || node->val == value1 || node->val == value2)
            return node;

        TreeNode* leftLCA = findLowestCommonAncestor(node->left, value1, value2);
        TreeNode* rightLCA = findLowestCommonAncestor(node->right, value1, value2);

        if (leftLCA == NULL)
            return rightLCA;
        
        if (rightLCA == NULL)
            return leftLCA;

        return node;
    }

    bool findPath(TreeNode* node, int targetValue, string& path) {
        
        if (node == NULL) 
            return false;

        if (node->val == targetValue) 
            return true;

        path.push_back('L');
        
        if (findPath(node->left, targetValue, path))
            return true;
        
        path.pop_back();

        path.push_back('R');

        if (findPath(node->right, targetValue, path)) 
            return true;
        
        path.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {

        TreeNode* lowestCommonAncestor = findLowestCommonAncestor(root, startValue, destValue);
        string pathToStart, pathToDest;

        findPath(lowestCommonAncestor, startValue, pathToStart);
        findPath(lowestCommonAncestor, destValue, pathToDest);

        string directions;

        directions.append(pathToStart.length(), 'U');
        directions.append(pathToDest);

        return directions;
    }
};



// Solved by LCA + DFS (Optimized)
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:

    bool findPath(TreeNode* node, int targetValue, string& path) {
        
        if (node == NULL) 
            return false;

        if (node->val == targetValue) 
            return true;

        path.push_back('L');
        
        if (findPath(node->left, targetValue, path))
            return true;
        
        path.pop_back();

        path.push_back('R');

        if (findPath(node->right, targetValue, path)) 
            return true;
        
        path.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        string startPath, destPath;
        findPath(root, startValue, startPath);
        findPath(root, destValue, destPath);

        int n = startPath.length(), m = destPath.length();

        string directions;
        int commonPathLength = 0;

        while (commonPathLength < min(n, m) && startPath[commonPathLength] == destPath[commonPathLength])
            commonPathLength++;

        for (int i = 0; i < n - commonPathLength; i++)
            directions += "U";

        for (int i = commonPathLength; i < m; i++)
            directions += destPath[i];

        return directions;
    }
};