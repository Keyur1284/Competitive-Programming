// Problem Link :- https://leetcode.com/problems/diagonal-traverse-ii/

// Solved using unordered_map
// Time Complexity :- O(n)  // n is the total number of elements in the grid
// Space Complexity :- O(n)

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        
        int n = nums.size();
        unordered_map<int, vector<int>> groups;
       
        for (int row = n - 1; row >= 0; row--) 
        {
            int m = nums[row].size();

            for (int col = 0; col < m; col++) 
            {
                int diagonal = row + col;
                groups[diagonal].emplace_back(nums[row][col]);
            }
        }
        
        vector<int> ans;
        int curr = 0;
        
        while (groups.count(curr)) 
        {
            for (auto &num : groups[curr]) 
            {
                ans.emplace_back(num);
            }
            
            curr++;
        }
        
        return ans;
    }
};



// Solved by BFS
// Time Complexity :- O(n)  // n is the total number of elements in the grid
// Space Complexity :- O(n^0.5)

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        
        int n = nums.size();
        queue<pair<int, int>> BFS;
        BFS.emplace(0, 0);
        vector<int> ans;
        
        while (!BFS.empty()) 
        {
            auto [row, col] = BFS.front();
            BFS.pop();
            
            ans.emplace_back(nums[row][col]);
            
            if (col == 0 && row + 1 < n) 
                BFS.emplace(row + 1, col);
            
            if (col + 1 < nums[row].size())
                BFS.emplace(row, col + 1);
        }
        
        return ans;
    }
};