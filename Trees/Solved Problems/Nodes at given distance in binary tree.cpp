// Problem Link :- https://practice.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/1

// Time Complexity :- O(NlogN)
// Space Complexity :- O(N)

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution{
public:
    
    int targetData;
    Node* targetNode = NULL;
    
    unordered_map<Node*, Node*> parent;
    unordered_set<Node*> vis;
    
    void findPar (Node* node, Node* par)
    {
        if (node == NULL)
            return;
            
        if (par)
            parent[node] = par;
            
        if (node->data == targetData)
            targetNode = node;
        
        findPar(node->left, node);
        findPar(node->right, node);
    }
    
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        this->targetData = target;
        findPar(root, NULL);
        
        queue<Node*> BFS;
        BFS.emplace(targetNode);
        vis.emplace(targetNode);
        
        while (k > 0 && !BFS.empty())
        {
            int size = BFS.size();
            
            while (size--)
            {
                Node* node = BFS.front();
                BFS.pop();
                
                if (node->left && vis.find(node->left) == vis.end())
                {
                    BFS.emplace(node->left);
                    vis.emplace(node->left);
                }
                
                if (node->right && vis.find(node->right) == vis.end())
                {
                    BFS.emplace(node->right);
                    vis.emplace(node->right);
                }
                
                if (parent.find(node) != parent.end() && vis.find(parent[node]) == vis.end())
                {
                    BFS.emplace(parent[node]);
                    vis.emplace(parent[node]);
                }
            }
            
            k--;
        }
        
        vector<int> nodes;
        
        while (!BFS.empty())
        {
            Node* node = BFS.front();
            BFS.pop();
            int data = node->data;
            nodes.emplace_back(data);
        }
    
        sort (nodes.begin(), nodes.end());
        
        return nodes;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends