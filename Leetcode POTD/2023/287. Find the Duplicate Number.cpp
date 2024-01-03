// Problem Link :- https://leetcode.com/problems/find-the-duplicate-number/

// Solved by modifying array nums
// Time Complexity : O(nlogn)
// Space Complexity : O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
                return nums[i];
        }

        return 0;
    }
};



// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int dup;

        for (int i = 0; i < nums.size(); i++)
        {
            int curr = abs(nums[i]);

            if (nums[curr] < 0)
            {
                dup = curr;
                break;
            }

            nums[curr] *= -1;
        }

        for (auto &it : nums)
            it = abs(it);

        return dup;
    }
};


// Solved by Binary Search
// Time Complexity : O(nlogn)
// Space Complexity : O(1)

class Solution {
public:

    int countLE (int val, vector<int> &nums)
    {
        int count = 0;

        for (auto &it : nums)
        {
            count += (it <= val);
        }

        return count;
    }

    int findDuplicate(vector<int>& nums) {
        
        int dup;
        int low = 1, high = nums.size(), mid;

        while (low <= high)
        {
            mid = (low + high) >> 1;

            if (countLE(mid, nums) > mid)
            {
                dup = mid;
                high = mid - 1;
            }

            else
                low = mid + 1;
        }

        return dup;
    }
};



// Solved by Bit Manipulation
// Time Complexity : O(nlogn)
// Space Complexity : O(1)

class Solution {
public:

    int countMaxBits (int num)
    {
        int bit = 0;

        while (num)
        {
            num /= 2;
            bit++;
        }

        return bit;
    }

    int findDuplicate(vector<int>& nums) {
        
        int dup = 0;
        int n = nums.size() - 1;
        int maxi = *max_element(nums.begin(), nums.end());
        int maxBits = countMaxBits (maxi);

        for (int bit = 0; bit < maxBits; bit++)
        {
            int mask = (1 << bit);
            int numCount = 0, baseCount = 0;

            for (int i = 0; i <= n; i++)
            {
                if (i & mask)
                    baseCount++;

                if (nums[i] & mask)
                    numCount++;
            }

            if (numCount > baseCount)
                dup |= mask;
        }

        return dup;
    }
};


// Solved by using Floyd's Tortoise and Hare (Cycle Detection) Algorithm    (Best Solution)
// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int tortoise = nums[0];
        int hare = nums[0];

        do
        {
            
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];

        } while (tortoise != hare);

        tortoise = nums[0];

        while (tortoise != hare)
        {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }

        return tortoise;
    }
};