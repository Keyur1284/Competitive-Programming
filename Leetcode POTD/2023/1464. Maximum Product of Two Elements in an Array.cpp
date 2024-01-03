// Problem Link :- https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/

// Solved by Brute Force Approach
// Time Complexity :- O(n^2)
// Space Complexity :- O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size(), maxProd = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int prod = (nums[i] - 1) * (nums[j] -1);
                maxProd = max(maxProd, prod);
            }
        }
        
        return maxProd;
    }
};



// Solved by Sorting
// Time Complexity :- O(nlogn)
// Space Complexity :- O(logn)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        return (nums[n - 1] - 1) * (nums[n - 2] - 1);
    }
};



// Solved without Sorting
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int biggest = 0, secondBiggest = 0;

        for (auto &num : nums) 
        {
            if (num > biggest) 
            {
                secondBiggest = biggest;
                biggest = num;
            } 
            
            else
                secondBiggest = max(secondBiggest, num);
        }
        
        return (biggest - 1) * (secondBiggest - 1);
    }
};