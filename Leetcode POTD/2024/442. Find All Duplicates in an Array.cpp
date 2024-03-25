// Problem Link :- https://leetcode.com/problems/find-all-duplicates-in-an-array/

// Solved using unordered_map
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        unordered_map<int, int> freq;
        vector<int> duplicates;

        for (auto &it : nums)
            freq[it]++;
        
        for (auto &it : freq)
        {
            if (it.second > 1)
                duplicates.emplace_back(it.first);
        }

        return duplicates;
    }
};



// Solved using constant space
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        vector<int> duplicates;
        
        for (int i = 0; i < nums.size(); i++)
        {
            int index = abs(nums[i]) - 1;
            
            if (nums[index] < 0)
                duplicates.emplace_back(index + 1);
            
            nums[index] = -nums[index];
        }

        return duplicates;
    }
};