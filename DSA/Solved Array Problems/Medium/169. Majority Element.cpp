// Problem Link :- https://leetcode.com/problems/majority-element/

// Solved by using unordered_map

// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map <int, int> mp;

        for (auto &it : nums)
            mp[it]++;

        for (auto &it : mp)
        {
            if (it.second > n/2)
                return it.first;
        }

        return -1;
    }
};

// Solved by sorting the array

// Time Complexity :- O(nlogn)
// Space Complexity :- O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n/2];
    }
};

// Solved by using bit manipulation

// Time Complexity :- O(nlogC); C is the max absolute value in nums vector
// Space Complexity :- O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        int majority_element = 0;

        for (int i = 0; i < 32; i++)
        {
            int bit = 1 << i;
            int count = 0;
            
            for (auto &it : nums)
            {
                if (bit & it)
                    count++;
            }

            if (count > n/2)
                majority_element |= bit;
        }

        return majority_element;
    }
};

// Solved by using Boyer Moore's Voting Algorithm

// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        int majority_element = 0, count = 0;

        for (auto &it : nums)
        {
            if (count == 0)
                majority_element = it;

            count += (it == majority_element) ? 1 : -1;
        }

        // We're directly returning the majority element as it is guaranteed that majority element always exists.
        // Had it been not given, we would traverse nums and check whether the element we found is 
        // really a majority element or not;
        
        return majority_element;
    }
};