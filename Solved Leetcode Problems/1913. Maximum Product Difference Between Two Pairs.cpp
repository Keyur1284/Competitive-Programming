// Problem Link :- https://leetcode.com/problems/maximum-product-difference-between-two-pairs/

// Solved by Sorting
// Time Complexity :- O(nlogn)
// Space Complexity :- O(logn)

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int maxProdDiff = (nums[n - 1] * nums[n - 2]) - (nums[0] * nums[1]);
        return maxProdDiff;
    }
};



// Solved without Sorting
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        
        int biggest = 0, secondBiggest = 0, smallest = 1e5, secondSmallest = 1e5;
        
        for (auto &it : nums)
        {
            if (it > biggest)
            {
                secondBiggest = biggest;
                biggest = it;
            }

            else if (it > secondBiggest)
            {
                secondBiggest = it;
            }
            
            if (it < smallest)
            {
                secondSmallest = smallest;
                smallest = it;
            }

            else if (it < secondSmallest)
            {
                secondSmallest = it;
            }
        }
        
        int maxProdDiff = (biggest * secondBiggest) - (smallest * secondSmallest);
        return maxProdDiff;
    }
};