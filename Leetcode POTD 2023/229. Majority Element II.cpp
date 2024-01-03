// Problem Link :- https://leetcode.com/problems/majority-element-ii/

// Time Complexity :- O(n)
// Space Complexity :- O(n)

// Solved by using unordered_map

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        unordered_map<int, int> mp;
        vector<int> ans;
        int n = nums.size();

        for (auto &it : nums)
            mp[it]++;

        for (auto &it : mp)
        {
            if (it.second > n/3)
                ans.emplace_back(it.first);

            if (ans.size() == 2)
                break;
        }

        return ans;
    }
};


// Solved by using Boyer Moore's Voting Algorithm

// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        vector<int> ans;
        int n = nums.size();
        int el1 = INT_MIN, el2 = INT_MIN, count1 = 0, count2 = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == el1)
                count1++;

            else if (nums[i] == el2)
                count2++;

            else if (count1 == 0)
            {
                el1 = nums[i];
                count1 = 1;
            }

            else if (count2 == 0)
            {
                el2 = nums[i];
                count2 = 1;
            }

            else
                count1--, count2--;
        }

        count1 = 0, count2 = 0;

        for (int i = 0; i < n; i++)
        {
            count1 += (el1 == nums[i]) ? 1 : 0;
            count2 += (el2 == nums[i]) ? 1 : 0;
        }

        if (count1 > n/3)
            ans.emplace_back(el1);

        if (count2 > n/3)
            ans.emplace_back(el2);
        
        return ans;
    }
};