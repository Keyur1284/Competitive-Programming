// Problem Link :- https://leetcode.com/problems/set-mismatch/

// Solved using unordered_map
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> ans(2);
        
        for (auto &it : nums)
            mp[it]++;
        
        for (int i = 1; i <= n; i++)
        {
            if (mp[i] == 2)
                ans[0] = i;

            if (mp[i] == 0)
                ans[1] = i;
        }
        
        return ans;
    }
};



// Solved using XOR
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans(2, 0), count(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            count[nums[i]]++;

            if (count[nums[i]] == 2)
                ans[0] = nums[i];

            ans[1] ^= (i + 1) ^ nums[i];
        }

        ans[1] ^= ans[0];

        return ans;
    }
};



// Solved by cyclic sort
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        int n = nums.size(), i = 0;

        for (int i = 0; i < n; i++) 
        {
            while (nums[i] != nums[nums[i] - 1]) 
            {
                swap(nums[i], nums[nums[i] - 1]);
            }   
        }

        for (int i = 0; i < n; i++) 
        {
            if (nums[i] != i + 1) 
                return {nums[i], i + 1};
        }

        return {-1, -1};
    }
};