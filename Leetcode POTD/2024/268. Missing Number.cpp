// Problem Link :- https://leetcode.com/problems/missing-number/

// Solved by Binary Search
// Time Complexity :- O(nlogn)
// Space Complexity :- O(logn)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size(), low = 0, high = n - 1, mid, ans;
        
        while (low <= high) 
        {
            mid = low + (high - low) / 2;
            
            if (nums[mid] == mid)
                low = mid + 1;
            
            else
            {
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
    }
};



class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size(), low = 0, high = n - 1, mid;
        
        while (low <= high) 
        {
            mid = low + (high - low) / 2;
            
            if (nums[mid] == mid)
                low = mid + 1;
            
            else
                high = mid - 1;
        }

        return low;
    }
};

// Solved by taking XOR
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size(), xor1 = 0, xor2 = 0;

        for (int i = 1; i <= n; i++)
            xor1 ^= i;

        for (int i = 0; i < n; i++)
            xor2 ^= nums[i];
        
        return (xor1 ^ xor2);
    }
};



// Solved by taking sum
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size(), sum = n * (n + 1)/2;

        for (int i = 0; i < n; i++)
            sum -= nums[i];
        
        return sum;
    }
};