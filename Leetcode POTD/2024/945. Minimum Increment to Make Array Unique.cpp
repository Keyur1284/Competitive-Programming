// Problem Link :- https://leetcode.com/problems/minimum-increment-to-make-array-unique/

// Solved by Sorting
// Time Complexity :- O(nlogn)
// Space Complexity :- O(logn)

class Solution {
public:
    int minIncrementForUnique(vector<int> &nums)
    {

        int n = nums.size(), moves = 0;
        sort(nums.begin(), nums.end());

        for (int i = 1; i < n; i++)
        {
            if (nums[i] <= nums[i - 1])
            {
                moves += nums[i - 1] - nums[i] + 1;
                nums[i] = nums[i - 1] + 1;
            }
        }

        return moves;
    }
};



// Solved by Counting Sort
// Time Complexity :- O(n + maxElement)
// Space Complexity :- O(n + maxElement)

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        int maxEle = *max_element(nums.begin(), nums.end());
        int minIncrements = 0;

        vector<int> frequencyCount(n + maxEle + 1, 0);

        for (auto &num : nums)
            frequencyCount[num]++;

        for (int i = 0; i <= n + maxEle; i++) 
        {
            if (frequencyCount[i] <= 1) 
                continue;

            int duplicates = frequencyCount[i] - 1;
            frequencyCount[i + 1] += duplicates;
            frequencyCount[i] = 1;
            minIncrements += duplicates;
        }

        return minIncrements;
    }
};