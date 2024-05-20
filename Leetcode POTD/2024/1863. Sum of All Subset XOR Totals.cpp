// Problem Link :- https://leetcode.com/problems/sum-of-all-subset-xor-totals/

// Solved by Backtracking
// Time Complexity :- O(2^n)
// Space Complexity :- O(n)

class Solution {
public:

    int xorSum = 0;

    void solve(int index, int xorVal, int &n, vector<int>& nums) {
        
        if (index == n) 
        {
            xorSum += xorVal;
            return;
        }
        
        solve(index + 1, xorVal ^ nums[index], n, nums);
        solve(index + 1, xorVal, n, nums);
    }

    int subsetXORSum(vector<int>& nums) {
        
        int n = nums.size();
        
        solve(0, 0, n, nums);

        return xorSum;
    }
};



// Solved by Bit Manipulation
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        
        int n = nums.size(), xorSum = 0;
        
        for (auto &num : nums) 
            xorSum |= num;
        
        return (xorSum << (n - 1));
    }
};