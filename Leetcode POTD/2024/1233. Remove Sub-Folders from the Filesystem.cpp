// Problem Link :- https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/

// Solved using unordered_set
// Time Complexity :- O(n * l^2)    n = number of folders
// Space Complexity :- O(n * l)     l = average length of folder path

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {

        unordered_set<string> folderSet(folder.begin(), folder.end());
        vector<string> rootFolders;

        for (string &folderPath : folder) 
        {
            bool isSubFolder = false;
            string prefix = folderPath;

            while (!prefix.empty()) 
            {
                auto pos = prefix.find_last_of('/');
                
                if (pos == string::npos) 
                    break;

                prefix = prefix.substr(0, pos);

                if (folderSet.count(prefix)) 
                {
                    isSubFolder = true;
                    break;
                }
            }

            if (!isSubFolder)
                rootFolders.emplace_back(folderPath);
        }

        return rootFolders;
    }
};



// Solved by Sorting
// Time Complexity :- O(n * l * log(n))    n = number of folders
// Space Complexity :- O(n * l)            l = average length of folder path

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {

        int n = folder.size();
        sort(folder.begin(), folder.end());
        vector<string> rootFolders;
        rootFolders.emplace_back(folder[0]);
        
        for (int i = 1; i < n; i++) 
        {
            string lastFolder = rootFolders.back();
            lastFolder += '/';
            
            if (folder[i].compare(0, lastFolder.size(), lastFolder) != 0)
                rootFolders.emplace_back(folder[i]);
        }

        return rootFolders;
    }
};



// Solved using Trie
// Time Complexity :- O(n * l)    n = number of folders
// Space Complexity :- O(n * l)   l = average length of folder path

class Solution {
private:
    struct TrieNode {
        
        bool isEndOfFolder;
        unordered_map<string, TrieNode*> children;
        
        TrieNode()
        {
            isEndOfFolder = false;
        }
    };

    TrieNode* root;

    void deleteTrie(TrieNode* node) 
    {
        if (node == nullptr) 
            return;
        
        for (auto& pair : node->children) 
        {
            deleteTrie(pair.second);
        }
        
        delete node;
    }

public:

    Solution()
    {
        root = new TrieNode();
    }
    
    ~Solution() 
    { 
        deleteTrie(root); 
    }

    vector<string> removeSubfolders(vector<string>& folder) {

        for (string &path : folder) 
        {
            TrieNode* currentNode = root;
            stringstream ss(path);
            string folderName;

            while (getline(ss, folderName, '/')) 
            {
                if (folderName.empty()) 
                    continue;

                if (currentNode->children.find(folderName) == currentNode->children.end())
                    currentNode->children[folderName] = new TrieNode();
                
                currentNode = currentNode->children[folderName];
            }

            currentNode->isEndOfFolder = true;
        }

        vector<string> rootFolders;
        
        for (string& path : folder) 
        {
            TrieNode* currentNode = root;
            stringstream ss(path);
            string folderName;
            bool isSubFolder = false;

            while (getline(ss, folderName, '/'))
            {
                if (folderName.empty()) 
                    continue;
                
                TrieNode* nextNode = currentNode->children[folderName];
                
                if (nextNode->isEndOfFolder && ss.rdbuf()->in_avail() != 0) 
                {
                    isSubFolder = true;
                    break;
                }

                currentNode = nextNode;
            }

            if (!isSubFolder) 
                rootFolders.emplace_back(path);
        }

        return rootFolders;
    }
};



class TrieNode {
public:
    
    bool isEnd;
    unordered_map<string, TrieNode*> children;
    
    TrieNode() 
    {
        isEnd = false;
    }
};

class Solution {
public:
    
    TrieNode *globalHead = new TrieNode();
    
    string extractFolder(string &folderName, int i) 
    {
        int k = i;
        i++;
        
        while (i < folderName.size() and folderName[i] != '/')
            i++;
        
        return folderName.substr(k + 1, i - (k + 1));
    }
    
    bool insertFolder(TrieNode *root, string &folderName, int i) 
    {
        if (i == folderName.size()) 
        {
            root->isEnd = true;
            return true;
        }
        
        if (root->isEnd)
            return false;
        
        string subFolderName  = extractFolder(folderName, i);
        
        if (!root->children.count(subFolderName))
            root->children[subFolderName] = new TrieNode();
        
        return insertFolder(root->children[subFolderName], folderName, i + subFolderName.size() + 1);
    }
    
    vector<string> removeSubfolders(vector<string>& folder) {
        
        sort(folder.begin(), folder.end());
        vector<string> rootFolders;
        
        for (auto &directory: folder) 
        {
            if (insertFolder(globalHead, directory, 0))
                rootFolders.emplace_back(directory);
        }
        
        return rootFolders;
    }
};