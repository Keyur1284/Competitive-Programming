// Problem Link :- https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/

// Solved by Brute Force Approach
// Time Complexity :- O(n^2 * log(n))
// Space Complexity :- O(n^2)

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        
        vector<int> subSums;

        for (int i = 0; i < n; i++)
        {
            int sum = 0;

            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                subSums.emplace_back(sum);
            }
        }

        sort(subSums.begin(), subSums.end());

        long ans = 0, mod = 1e9 + 7;

        for (int i = left; i <= right; i++)
            ans = (ans + subSums[i - 1]) % mod;

        return ans;
    }
};



// Solved using priority_queue
// Time Complexity :- O(n^2 * log(n))
// Space Complexity :- O(n)

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for (int i = 0; i < n; i++) 
            pq.emplace(nums[i], i);

        int ans = 0, mod = 1e9 + 7;

        for (int i = 1; i <= right; i++) 
        {
            auto it = pq.top();
            pq.pop();
            
            if (i >= left) 
                ans = (ans + it.first) % mod;
            
            if (it.second < n - 1) 
            {
                it.first += nums[++it.second];
                pq.emplace(it);
            }
        }
        
        return ans;
    }
};



// Solved by Binary Search + Sliding Window
// Time Complexity :- O(n * log(sum))
// Space Complexity :- O(1)

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        
        long result = (sumOfFirstK(nums, n, right) - sumOfFirstK(nums, n, left - 1)) %mod;
        return (result + mod) % mod;
    }

private:
    
    int mod = 1e9 + 7;

    pair<int, long long> countAndSum(vector<int>& nums, int n, int target) {
        int count = 0;
        long long currentSum = 0, totalSum = 0, windowSum = 0;
        for (int right = 0, left = 0; right < n; right++) 
        {
            currentSum += nums[right];
            windowSum += nums[right] * (right - left + 1);
            
            while (currentSum > target) 
            {
                windowSum -= currentSum;
                currentSum -= nums[left++];
            }
            
            count += right - left + 1;
            totalSum += windowSum;
        }
        return {count, totalSum};
    }

    long long sumOfFirstK(vector<int>& nums, int n, int k) {
        
        int minSum = *min_element(nums.begin(), nums.end());
        int maxSum = accumulate(nums.begin(), nums.end(), 0);
        int left = minSum, right = maxSum, ans = left;

        while (left <= right) 
        {
            int mid = (left + right) >> 1;

            if (countAndSum(nums, n, mid).first >= k)
            {
                ans = mid;
                right = mid - 1;
            }

            else
                left = mid + 1;
        }

        auto [count, sum] = countAndSum(nums, n, ans);

        return sum - ans * (count - k);
    }
};