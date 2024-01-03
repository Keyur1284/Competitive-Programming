// Problem Link :- https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/

// Solved by Prefix Sum
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
       
        int n = nums.size();
        vector<int> pref = {nums[0]};

        for (int i = 1; i < n; i++) 
        {
            pref.emplace_back(pref[i - 1] + nums[i]);
        }
        
        vector<int> ans;

        for (int i = 0; i < n; i++) 
        {
            int leftSum = pref[i] - nums[i];
            int rightSum = pref[n - 1] - pref[i];
            
            int leftCount = i;
            int rightCount = n - 1 - i;
            
            int leftTotal = leftCount * nums[i] - leftSum;
            int rightTotal = rightSum - rightCount * nums[i];
            
            ans.emplace_back(leftTotal + rightTotal);
        }
        
        return ans;
    }
};



// Solved without Prefix Sum Vector
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        int leftSum = 0;
        vector<int> ans;

        for (int i = 0; i < n; i++) 
        {
            int rightSum = totalSum - leftSum - nums[i];
            
            int leftCount = i;
            int rightCount = n - 1 - i;
            
            int leftTotal = leftCount * nums[i] - leftSum;
            int rightTotal = rightSum - rightCount * nums[i];
            
            ans.emplace_back(leftTotal + rightTotal);
            leftSum += nums[i];
        }
        
        return ans;
    }
};