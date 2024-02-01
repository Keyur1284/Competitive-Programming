// Problem Link :- https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/

// Solved by Sorting
// Time Complexity :- O(nlogn)
// Space Complexity :- O(logn)

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>> divArr, empty;

        for (int i = 0; i <= n - 3; i+= 3)
        {
            if (nums[i + 2] - nums[i] <= k)
                divArr.push_back({nums[i], nums[i + 1], nums[i + 2]});

            else
                return empty;
        }

        return divArr;
    }
};