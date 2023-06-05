// Problem Link :- https://practice.geeksforgeeks.org/problems/find-the-closest-element-in-bst/1

// Time Complexity :- O(H)      H -> Height of BST
// Space Complexity :- O(1)

// Solved by Recursive Approach

/*
Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
    public:
    //Function to find the least absolute difference between any node
	//value of the BST and the given integer.
	
	int mini = INT_MAX;
	
	void DFS (Node *node, int &K)
	{
	    if (node == NULL)
	        return;
	        
	    mini = min(mini, abs(node->data - K));
	    
	    if (node->data > K)
	        DFS (node->left, K);
	        
	    else if (node->data < K)
	        DFS (node->right, K);
	}
	
    int minDiff(Node *root, int K)
    {
        DFS (root, K);
        return mini;
    }
};


/*
Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
    public:
    //Function to find the least absolute difference between any node
	//value of the BST and the given integer.
	
    int minDiff(Node *root, int K)
    {
        if (root == NULL)
            return K;
            
        int diff = abs(root->data - K);
        
        if (root->data > K)
            return min(diff, minDiff (root->left, K));
            
        else 
            return min(diff, minDiff (root->right, K));
    }
};


// Solved by Iterative Approach

/*
Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
    public:
    //Function to find the least absolute difference between any node
	//value of the BST and the given integer.
	
    int minDiff(Node *root, int K)
    {
        int mini = K;
        queue<Node*> BFS;
        BFS.emplace(root);
        
        while (!BFS.empty())
        {
            Node* node = BFS.front();
            BFS.pop();
            
            if (node == NULL)
                continue;
                
            mini = min(mini, abs(node->data - K));
            
            if (node->data > K)
                BFS.emplace(node->left);
                
            else
                BFS.emplace(node->right);
        }
        
        
        return mini;
    }
};