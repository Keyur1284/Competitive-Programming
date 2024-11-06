// Problem Link :- https://leetcode.com/problems/find-if-array-can-be-sorted/

// Solved by Bubble Sort
// Time Complexity :- O(n^2)
// Space Complexity :- O(n)

class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> setBits;

        for (auto &it : nums)
        {
            int bits = __builtin_popcount(it);
            setBits.emplace_back(bits);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if (nums[j] > nums[j + 1])
                {
                    if (setBits[j] != setBits[j + 1])
                        return false;

                    swap(nums[j], nums[j + 1]);
                }
            }
        }

        return true;
    }
};



// Solved by forward and backward pass
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> values = nums;
        
        for (int i = 0; i < n - 1; i++) 
        {
            if (values[i] <= values[i + 1])
                continue;
            
            else 
            {
                if (__builtin_popcount(values[i]) == __builtin_popcount(values[i + 1]))
                    swap(values[i], values[i + 1]);
                
                else
                    return false;
            }
        }

        for (int i = n - 1; i >= 1; i--) 
        {
            if (values[i] >= values[i - 1])
                continue;
            
            else 
            {
                if (__builtin_popcount(values[i]) == __builtin_popcount(values[i - 1]))
                    swap(values[i], values[i - 1]);
                
                else
                    return false;
            }
        }
        
        return true;
    }
};



// Solved by forming segments
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    bool canSortArray(vector<int>& nums) {

        int n = nums.size();
        int numOfSetBits = __builtin_popcount(nums[0]), maxOfSegment = nums[0], minOfSegment = nums[0];
        int maxOfPrevSegment = INT_MIN;

        for (int i = 1; i < n; i++) 
        {
            if (__builtin_popcount(nums[i]) == numOfSetBits) 
            {
                maxOfSegment = max(maxOfSegment, nums[i]);
                minOfSegment = min(minOfSegment, nums[i]);
            } 
            
            else 
            {  
                if (minOfSegment < maxOfPrevSegment)
                    return false;
                
                maxOfPrevSegment = maxOfSegment;

                maxOfSegment = nums[i];
                minOfSegment = nums[i];
                numOfSetBits = __builtin_popcount(nums[i]);
            }
        }

        if (minOfSegment < maxOfPrevSegment)
            return false;
        
        return true;
    }
};