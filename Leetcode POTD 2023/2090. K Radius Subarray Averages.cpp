// Problem Link :- https://leetcode.com/problems/k-radius-subarray-averages/

// Solved by Prefix Sum
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> averages(n, -1);

        if (n <= 2*k)
            return averages;

        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + nums[i];

        for (int i = k; i < n - k; i++)
        {
            int right = i + k, left = i - k;
            long long sum = pref[right + 1] - pref[left];
            int avg = sum/(2 * k + 1);

            averages[i] = avg;
        }

        return averages;
    }
};



// Solved by Sliding Window
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> averages(n, -1);

        if (n <= 2*k)
            return averages;

        long long sum = 0;

        for (int i = 0; i <= 2 * k; i++)
        {
            sum += nums[i];
        }

        for (int i = k; i < n - k; i++)
        {
            int avg = sum/(2 * k + 1);
            averages[i] = avg;

            if (i + k + 1 < n)
            {
                sum -= nums[i - k];
                sum += nums[i + k + 1];
            }
        }

        return averages;
    }
};