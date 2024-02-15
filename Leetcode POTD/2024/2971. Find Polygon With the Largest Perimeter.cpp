// Problem Link :- https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/

// Solved by Sorting
// Time Complexity :- O(nlogn)
// Space Complexity :- O(1)

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long prevSum = 0, maxPeri = -1;

        for (int i = 0; i < n; i++)
        {
            if (i >= 2 && prevSum > nums[i])
            {
                maxPeri = prevSum + nums[i];
            }

            prevSum += nums[i];
        }

        return maxPeri;
    }
};



// There is no need to impose the condition of i >= 2
// In first iteration, prevSum will be 0 and nums[0] > 0
// In second iteration, prevSum will be nums[0] and nums[1] > nums[0]
// Hence, for i < 2 our if condition will be false

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        long long prevSum = 0, maxPeri = -1;

        for (auto &it : nums)
        {
            if (prevSum > it)
            {
                maxPeri = prevSum + it;
            }

            prevSum += it;
        }

        return maxPeri;
    }
};