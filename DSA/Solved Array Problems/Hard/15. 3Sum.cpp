// Problem Link :- https://leetcode.com/problems/3sum/

// Time Complexity :- O(n^2 + nlogn)
// Space Complexity :- O(n)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        set<vector<int>> triplets;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int j = i + 1, k = n - 1;

            while (j < k)
            {
                int val = nums[i] + nums[j] + nums[k];
                
                if (val == 0)
                {
                    triplets.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                } 

                else if (val < 0)
                    j++;

                else if (val > 0)
                    k--;
            }
        }

        vector<vector<int>> ans (triplets.begin(), triplets.end());

        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1, k = n - 1;

            while (j < k)
            {
                int val = nums[i] + nums[j] + nums[k];

                if (val == 0)
                {
                    vector<int> vec = {nums[i], nums[j], nums[k]};
                    ans.push_back(vec);
                    
                    j++;
                    k--;

                    while (j < k && nums[j] == nums[j - 1])
                        j++;

                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                } 

                else if (val < 0)
                    j++;

                else if (val > 0)
                    k--;
            }
        }

        return ans;
    }
};