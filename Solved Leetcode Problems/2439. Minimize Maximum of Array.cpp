// Problem Link :- https://leetcode.com/problems/minimize-maximum-of-array/

// Time Complexity :- O(nlogn)
// Space Complexity :- O(1)

class Solution {
public:

    bool check (int maxi, int n, vector<int> &nums)
    {
        long long sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];

            if (sum > (long long) maxi * (i + 1))
                return false;
        }

        return true;
    }

    int minimizeArrayValue(vector<int>& nums) {
        
        int n = nums.size();
        int low = 0, high = *max_element(nums.begin(), nums.end()), mid, ans = high;

        while (low <= high)
        {
            mid = (low + high) >> 1;

            if (check(mid, n, nums))
            {
                ans = mid;
                high = mid - 1;
            }

            else
                low = mid + 1;
        }

        return ans;
    }
};

// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        
        int n = nums.size();
        long long ans = 0, prefSum = 0;

        for (int i = 0; i < n; i++)
        {
            prefSum += nums[i];
            ans = max(ans, (prefSum + i)/(i + 1));
        }

        return ans;
    }
};