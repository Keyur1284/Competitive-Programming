// Problem Link :- https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/

// Solved by DP
// Time Complexity :- O(n^2)
// Space Complexity :- O(n)

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> lisLength(n, 1), ldsLength(n, 1);

        for (int i = 0; i < n; i++) 
        {
            for (int j = i - 1; j >= 0; j--) 
            {
                if (nums[i] > nums[j])
                    lisLength[i] = max(lisLength[i], lisLength[j] + 1);
            }
        }

        for (int i = n - 1; i >= 0; i--) 
        {
            for (int j = i + 1; j < n; j++) 
            {
                if (nums[i] > nums[j])
                    ldsLength[i] = max(ldsLength[i], ldsLength[j] + 1);
            }
        }

        int minRemovals = INT_MAX;

        for (int i = 0; i < n; i++) 
        {
            if (lisLength[i] > 1 && ldsLength[i] > 1)
                minRemovals = min(minRemovals, n - (lisLength[i] + ldsLength[i] - 1));
        }

        return minRemovals;
    }
};



// Solved by Binary Search
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:
    vector<int> getLongestIncreasingSubsequenceLength(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> lisLen(n);
        vector<int> lis = {nums[0]};

        for (int i = 0; i < n; i++) 
        {
            int index = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();

            if (index == lis.size())
                lis.emplace_back(nums[i]);
            
            else
                lis[index] = v[i];

            lisLen[i] = lis.size();
        }

        return lisLen;
    }

    int minimumMountainRemovals(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> lisLength = getLongestIncreasingSubsequenceLength(nums);

        reverse(nums.begin(), nums.end());
        vector<int> ldsLength = getLongestIncreasingSubsequenceLength(nums);
        reverse(ldsLength.begin(), ldsLength.end());

        int minRemovals = INT_MAX;

        for (int i = 0; i < n; i++) 
        {
            if (lisLength[i] > 1 && ldsLength[i] > 1)
                minRemovals = min(minRemovals, n - (lisLength[i] + ldsLength[i] - 1));
        }

        return minRemovals;
    }
};