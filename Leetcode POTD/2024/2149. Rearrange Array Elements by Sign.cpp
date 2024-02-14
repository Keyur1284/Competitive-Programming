// Problem Link :- https://leetcode.com/problems/rearrange-array-elements-by-sign/

// Solved by seperating the positive and negative numbers
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> ans(n), pos, neg;

        for (auto &it : nums)
        {
            if (it > 0)
                pos.emplace_back(it);

            else
                neg.emplace_back(it);
        }

        for (int i = 0; i < n/2; i++)
        {
            ans[2 * i] = pos[i];
            ans[2 * i + 1] = neg[i];
        }

        return ans;
    }
};



// Solving using two pointers
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int n = nums.size();
        int pos = 0, neg = 1;
        vector<int> ans(n);

        for (auto &it : nums)
        {
            if (it > 0)
            {
                ans[pos] = it;
                pos += 2;
            }

            else
            {
                ans[neg] = it;
                neg += 2;
            }
        }

        return ans;
    }
};