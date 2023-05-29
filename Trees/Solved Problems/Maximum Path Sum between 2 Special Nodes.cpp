// Problem Link :- https://practice.geeksforgeeks.org/problems/maximum-path-sum/1

// Time Complexity : O(N)
// Space Complexity : O(N)


/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
public:
    
    int maxi = INT_MIN;
    
    int DFS (Node* node, Node* head)
    {
        if (node == NULL)
            return 0;
            
        int left = DFS(node->left, head);
        int right = DFS(node->right, head);
        
        if (node == head)
        {
            maxi = max(maxi, node->data + left + right);
        }
        
        if (node->left == NULL)
            return node->data + right;
            
        if (node->right == NULL)
            return node->data + left; 
        
        
        maxi = max(maxi, node->data + left + right);
        
        return node->data + max(left, right);
    }
    
    int maxPathSum(Node* root)
    {
        Node* head = root;
        DFS(root, head);
        
        return maxi;
    }
};



/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
public:
    
    int maxi = INT_MIN;
    
    int DFS (Node* node)
    {
        if (node == NULL)
            return 0;
            
        int left = DFS(node->left);
        int right = DFS(node->right);
        
        if (node->left == NULL)
            return node->data + right;
            
        if (node->right == NULL)
            return node->data + left; 
        
        maxi = max(maxi, node->data + left + right);
        
        return node->data + max(left, right);
    }
    
    int maxPathSum(Node* root)
    {
        int ans = DFS(root);
        
        if (root->left && root->right)
            return maxi;
        
        return max(maxi, ans);
    }
};
