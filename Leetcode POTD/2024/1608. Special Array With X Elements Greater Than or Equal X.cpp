// Problem Link :- https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/

// Solved by Binary Search
// Time Complexity :- O(nlogn)
// Space Complexity :- O(1)

class Solution {
public:

    int countGte(int x, vector<int> &nums)
    {
        int gte = 0;

        for (auto &it : nums)
            gte += (it >= x);

        return gte;
    }

    int specialArray(vector<int>& nums) {
        
        int low = 1, high = nums.size();

        while (low <= high)
        {
            int mid = (low + high) >> 1;

            int gte = countGte(mid, nums);

            if (gte == mid)
                return mid;

            if (gte < mid)
                high = mid - 1;

            else
                low = mid + 1;
        }

        return -1;
    }
};



// Solved by Sorting + Binary Search
// Time Complexity :- O(nlogn)
// Space Complexity :- O(logn)

class Solution {
public:

    int specialArray(vector<int>& nums) {

        int n = nums.size();    
        sort(nums.begin(), nums.end());

        for (int i = 1; i <= n; i++)
        {
            int gteIndex = lower_bound(nums.begin(), nums.end(), i) - nums.begin();

            if (n - gteIndex == i)
                return i;
        }

        return -1;
    }
};



// Solved by Counting Sort
// Time Complexity :- O(n + 1000)
// Space Complexity :- O(1000)

class Solution {
public:

    int specialArray(vector<int>& nums) {
        
        vector<int> freq(1001, 0);

        for (auto &it : nums)
            freq[it]++;

        int total = nums.size();

        for (int i = 0; i <= 1000; i++)
        {
            if (total == i)
                return i;

            total -= freq[i];
        }

        return -1;
    }
};



// Solved by Counting Sort
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:

    int specialArray(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> freq(n + 1, 0);

        for (auto &it : nums)
            freq[min(it, n)]++;

        int gte = 0;

        for (int i = n; i >= 0; i--)
        {
            gte += freq[i];

            if (gte == i)
                return i;
        }

        return -1;
    }
};