// Problem Link :- https://leetcode.com/problems/the-number-of-beautiful-subsets/

// Solved by Backtracking + Sorting
// Time Complexity :- O(nlogn + 2^n)
// Space Complexity :- O(n)

class Solution {
public:

    int beautifulCount = 0;

    int solve(int index, int &n, int &k, unordered_map<int, int> &freq, vector<int> &nums)
    {
        if (index == n)
            return 1;

        int notTake = solve(index + 1, n, k, freq, nums);
        int take = 0;

        if (freq[nums[index] - k] == 0)
        {
            freq[nums[index]]++;
            take = solve(index + 1, n, k, freq, nums);
            freq[nums[index]]--;
        }

        return take + notTake;
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        unordered_map<int, int> freq;
        return solve(0, n, k, freq, nums) - 1;
    }
};



// Solved by Bitmasking
// Time Complexity :- O(n * 2^n)
// Space Complexity :- O(n)

class Solution {
public:

    int beautifulCount = 0;

    int solve(int index, int mask, int &n, int &k, vector<int> &nums)
    {
        if (index == n)
            return (mask > 0);

        int notTake = solve(index + 1, mask, n, k, nums);
        int take = 0;
        bool isBeautiful = true;

        for (int j = 0; j < index && isBeautiful; j++)
        {
            if ((1 << j) & mask)
                isBeautiful = (abs(nums[index] - nums[j]) != k);
        }

        if (isBeautiful)
            take = solve(index + 1, mask | (1 << index), n, k, nums);

        return take + notTake;
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        
        int n = nums.size(), mask = 0;
        return solve(0, mask, n, k, nums);
    }
};