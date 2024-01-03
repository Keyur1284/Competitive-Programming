// Problem Link :- https://leetcode.com/problems/frequency-of-the-most-frequent-element/

// Solved by Sorting + Sliding Window
// Time Complexity :- O(nlogn)
// Space Complexity :- O(logn)

class Solution {
public:

    int maxFrequency(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());

        int n = nums.size(), maxFreq = 0;
        long sum = 0;

        for (int left = 0, right = 0; right < n; right++)
        {
            sum += nums[right];

            while (1LL * (right - left + 1) * nums[right] - sum > k)
                sum -= nums[left++];

            int len = right - left + 1;
            maxFreq = max(maxFreq, len);
        }

        return maxFreq;
    }
};



// Solved by Sorting + Optimized Sliding Window
// Time Complexity :- O(nlogn)
// Space Complexity :- O(logn)

class Solution {
public:

    int maxFrequency(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());

        int n = nums.size(), left = 0;
        long sum = 0;

        for (int right = 0; right < n; right++)
        {
            sum += nums[right];

            if (1LL * (right - left + 1) * nums[right] - sum > k)
                sum -= nums[left++];
        }

        return n - left;
    }
};



// Solved by Sorting + Binary Search
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:

    int findFreq (int index, vector<long> &pref, vector<int>& nums, int k)
    {
        int target = nums[index];
        int low = 0, high = index, ans = index, mid;

        while (low <= high)
        {
            mid = (low + high) >> 1;
            int len = index - mid + 1;
            long sum = pref[index] - pref[mid] + nums[mid];
            int ops = 1LL * len * target - sum;

            if (ops > k)
                low = mid + 1;

            else
            {
                ans = mid;
                high = mid - 1;
            }
        }

        return index - ans + 1;
    }

    int maxFrequency(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        vector<long> pref(n);
        pref[0] = nums[0];

        for (int i = 1; i < n; i++)
            pref[i] = pref[i - 1] + nums[i];

        int maxFreq = 0;

        for (int i = 0; i < n; i++)
        {
            int freq = findFreq(i, pref, nums, k);
            maxFreq = max(maxFreq, freq);
        }

        return maxFreq;
    }
};