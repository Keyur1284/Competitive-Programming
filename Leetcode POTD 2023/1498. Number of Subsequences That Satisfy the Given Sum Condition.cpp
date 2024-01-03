// Problem Link :- https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/

// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

// Solved using inbuilt upper_bound function

class Solution {
public:

    int MOD = 1e9 + 7;

    int numSubseq(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<int> pow(n);
        pow[0] = 1;

        for (int i = 1; i < n; i++)
        {
            pow[i] = (pow[i - 1] * 2) % MOD;
        }

        int ans = 0;

        for (int left = 0; left < n; left++)
        {
            auto right = upper_bound(nums.begin(), nums.end(), target - nums[left]) - nums.begin() - 1;

            if (left <= right)
            {
                ans += pow[right - left];
                ans %= MOD;
            }
        }

        return ans;
    }
};


// Solved by Binary Search

class Solution {
public:

    int MOD = 1e9 + 7;

    int binarySearch (int target, vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1, mid, ans = left;

        while (left <= right)
        {
            mid = (left + right) >> 1;

            if (nums[mid] <= target)
            {
                left = mid + 1;
                ans = left;
            }

            else
                right = mid - 1;
        }

        return ans;
    }

    int numSubseq(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<int> pow(n);
        pow[0] = 1;

        for (int i = 1; i < n; i++)
        {
            pow[i] = (pow[i - 1] * 2) % MOD;
        }

        int ans = 0;

        for (int left = 0; left < n; left++)
        {
            int right = binarySearch(target - nums[left], nums) - 1;

            if (left <= right)
            {
                ans += pow[right - left];
                ans %= MOD;
            }
        }

        return ans;
    }
};


// Solved by Two pointer Approach

class Solution {
public:

    int MOD = 1e9 + 7;

    int numSubseq(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<int> pow(n);
        pow[0] = 1;

        for (int i = 1; i < n; i++)
        {
            pow[i] = (pow[i - 1] * 2) % MOD;
        }

        int ans = 0, left = 0, right = n - 1;

        while (left <= right)
        {
            if (nums[left] + nums[right] > target)
                right--;

            else
            {
                ans += pow[right - left];
                ans %= MOD;

                left++;
            }
        }

        return ans;
    }
};


// Solved by Binary Exponentiation

class Solution {
public:

    int MOD = 1e9 + 7;

    int mod_power (int base, int exp)
    {
        int res = 1;

        while (exp)
        {
            if (exp % 2)
            {
                res = (1LL * res * base) % MOD;
                exp--;
            }

            else
            {
                base = (1LL * base * base) % MOD;
                exp /= 2;
            }
        }

        return res;
    }

    int binarySearch (int target, vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1, mid, ans = left;

        while (left <= right)
        {
            mid = (left + right) >> 1;

            if (nums[mid] <= target)
            {
                left = mid + 1;
                ans = left;
            }

            else
                right = mid - 1;
        }

        return ans;
    }

    int numSubseq(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());

        int n = nums.size();

        int ans = 0;

        for (int left = 0; left < n; left++)
        {
            int right = binarySearch(target - nums[left], nums) - 1;

            if (left <= right)
            {
                ans += mod_power(2, right - left);
                ans %= MOD;
            }
        }

        return ans;
    }
};