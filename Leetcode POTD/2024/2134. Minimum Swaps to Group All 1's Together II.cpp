// Problem Link :- https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/

// Solved by creating circular array
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int minSwaps(vector<int> &nums) {

        int totalOnes = accumulate(nums.begin(), nums.end(), 0);
        vector<int> circularNums = nums;

        for (auto &it : nums)
            circularNums.emplace_back(it);

        int n = circularNums.size(), maxOnes = 0, ones = 0;

        for (int i = 0; i < n; i++)
        {
            ones += circularNums[i];

            if (i >= totalOnes)
                ones -= circularNums[i - totalOnes];

            maxOnes = max(ones, maxOnes);
        }

        return totalOnes - maxOnes;
    }
};



// Solved by Sliding Window
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:

    int findMinSwaps(vector<int> &nums, int val)
    {
        int totalVals = 0;

        for (auto &it : nums)
            totalVals += (it == val);

        int n = nums.size(), maxValCount = 0, valCount = 0;

        for (int i = 0; i < n; i++)
        {
            valCount += (nums[i] == val);

            if (i >= totalVals)
                valCount -= (nums[i - totalVals] == val);

            maxValCount = max(valCount, maxValCount);
        }

        return totalVals - maxValCount;
    }

    int minSwaps(vector<int>& nums) {
        
        int groupZeros = findMinSwaps(nums, 0);
        int groupOnes = findMinSwaps(nums, 1);

        return min(groupZeros, groupOnes);
    }
};



class Solution {
public:
    int minSwaps(vector<int>& nums) {

        int n = nums.size(), minimumSwaps = n;
        int totalOnes = accumulate(nums.begin(), nums.end(), 0);
        int onesCount = nums[0];

        for (int start = 0, end = 0; start < n; start++) 
        {
            if (start)
                onesCount -= nums[start - 1];

            while (end - start + 1 < totalOnes) 
            {
                end++;
                onesCount += nums[end % n];
            }

            minimumSwaps = min(minimumSwaps, totalOnes - onesCount);
        }

        return minimumSwaps;
    }
};