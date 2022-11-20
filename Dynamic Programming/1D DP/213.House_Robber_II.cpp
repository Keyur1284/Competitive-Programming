//Problem Link :- https://leetcode.com/problems/house-robber-ii/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 1)
            return nums[0];
        
        int prev = nums[0];
        int prev2 = 0;
        int curr;
        
        for (int i = 1; i < n - 1; i++)
        {
            int pick = nums[i];
            
            if (i > 1)
                pick += prev2;
            
            int nonPick = 0 + prev;
            
            curr = max(pick, nonPick);
            prev2 = prev;
            prev = curr;
        }
        
        int ans1 = prev;
        
        prev = nums[1];
        prev2 = 0;
        
        for (int i = 2; i<n; i++)
        {
            int pick = nums[i];
            
            if (i > 2)
                pick += prev2;
            
            int nonPick = 0 + prev;
            
            curr = max(pick, nonPick);
            prev2 = prev;
            prev = curr;
        }
        
        int ans2 = prev;
        
        return max(ans1, ans2);
    }
};


//Another code
class Solution {
public:
    int robber (vector <int> &nums)
    {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;
        int curr;
        
        for (int i = 1; i < n; i++)
        {
            int pick = nums[i];
            
            if (i > 1)
                pick += prev2;
            
            int nonPick = 0 + prev;
            
            curr = max(pick, nonPick);
            prev2 = prev;
            prev = curr;
        }
        
        return prev;
    }
    
    int rob(vector<int> &nums) {
        
        int n = nums.size();
        
        if (n == 1)
            return nums[0];
        
        vector <int> temp1, temp2;
        
        for (int i = 0; i<n; i++)
        {
            if (i != n - 1)
                temp1.emplace_back(nums[i]);
            
            if (i != 0)
                temp2.emplace_back(nums[i]);        
        }

        return max(robber(temp1), robber(temp2));
    }
};