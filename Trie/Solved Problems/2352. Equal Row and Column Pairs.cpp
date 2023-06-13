// Problem Link :- https://leetcode.com/problems/equal-row-and-column-pairs/

// Solved by Brute Force Approach
// Time Complexity :- O(n^3)
// Space Complexity :- O(1)

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {

        int n = grid.size(), equal = 0;

        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                bool flag = true;

                for (int k = 0; k < n; k++)
                {
                    if (grid[row][k] != grid[k][col])
                    {
                        flag = false;
                        break;
                    }
                }

                equal += flag;
            }
        }
        
        return equal;
    }
};



// Solved by using map
// Time Complexity :- O(n^2)
// Space Complexity :- O(n^2)

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {

        int n = grid.size(), equal = 0;
        map<vector<int>, int> mp;

        for (auto &row : grid)
            mp[row]++;

        for (int col = 0; col < n; col++)
        {
            vector<int> column;

            for (int row = 0; row < n; row++)
            {
                column.emplace_back(grid[row][col]);
            }

            equal += mp[column];
        }
        
        return equal;
    }
};



// Solved by using Trie Data Structure
// Time Complexity :- O(n^2)
// Space Complexity :- O(n^2)

class TrieNode {
public:

    int count;
    unordered_map<int, TrieNode*> child;

    TrieNode ()
    {
        count = 0;
    }
};

class Trie {
public:

    TrieNode* root;

    Trie ()
    {
        root = new TrieNode();
    }

    void insert (vector<int> &row)
    {
        TrieNode* node = root;

        for (auto &num : row)
        {
            if (node->child.find(num) == node->child.end())
                node->child[num] = new TrieNode ();

            node = node->child[num];
        }

        node->count += 1;
    }

    int findEqualPairs (vector<vector<int>> &grid)
    {
        int n = grid.size(), equal = 0;

        for (int col = 0; col < n; col++)
        {
            TrieNode* node = root;

            for (int row = 0; row < n; row++)
            {
                if (node->child.find(grid[row][col]) == node->child.end())
                    break;

                node = node->child[grid[row][col]];
            }

            equal += node->count;
        }

        return equal;
    }
};

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {

        Trie obj;

        for (auto &row : grid)
            obj.insert(row);

        int equal = obj.findEqualPairs (grid);
        
        return equal;
    }
};