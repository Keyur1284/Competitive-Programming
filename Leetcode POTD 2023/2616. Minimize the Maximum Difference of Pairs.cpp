// Problem Link :- https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/

// Solved by Binary Search
// Time Complexity :- O(nlogn)
// Space Complexity :- O(1)

class Solution {
public:

    bool check (int diff, int n, vector<int>& nums, int p)
    {
        int pairs = 0;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] - nums[i - 1] <= diff)
            {
                pairs++;
                i++;
            }
        }

        return (pairs >= p);
    }

    int minimizeMax(vector<int>& nums, int p) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int low = 0, high = nums[n - 1] - nums[0], mid;

        while (low <= high)
        {
            mid = (low + high) >> 1;
            
            if (check(mid, n, nums, p))
                high = mid - 1;

            else
                low = mid + 1;
        }

        return low;
    }
};