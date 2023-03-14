// Problem Link :- https://leetcode.com/problems/two-sum/

// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> mp;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(mp.find(target - nums[i]) != mp.end())
                return {mp[target - nums[i]], i};
            
            mp[nums[i]] = i;
        }

        return {};
    }
};


// Time Complexity :- O(nlogn)
// Space Complexity :- O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();
        vector<pair<int, int>> vec;
        
        for (int i = 0; i < n; i++)
            vec.emplace_back(nums[i], i);

        sort(vec.begin(), vec.end());

        int left = 0, right = n - 1;

        while (left < right)
        {
            int sum = vec[left].first + vec[right].first;
            
            if (target == sum)
            {
                return {vec[left].second, vec[right].second};
            }

            (sum < target) ? left++ : right--;
        }

        return {};
    }
};