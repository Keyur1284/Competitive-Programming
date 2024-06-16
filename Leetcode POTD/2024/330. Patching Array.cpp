// Problem Link :- https://leetcode.com/problems/patching-array/

// Solved by Greedy Approach
// Time Complexity :- O(logn + m)
// Space Complexity :- O(1)

class Solution
{
public:
    int minPatches(vector<int> &nums, int n)
    {

        int m = nums.size(), patchCount = 0, index = 0;
        long maxSumSoFar = 0;

        while (maxSumSoFar < n)
        {
            if (index < m && maxSumSoFar + 1 >= nums[index])
                maxSumSoFar += nums[index++];

            else
            {
                maxSumSoFar += maxSumSoFar + 1;
                patchCount++;
            }
        }

        return patchCount;
    }
};