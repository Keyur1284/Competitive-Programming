//Problem Link :- https://leetcode.com/problems/burst-balloons/

//Solved by Memoization Method

class Solution {
public:
    
    int func (int i, int j, vector <vector<int>> &dp, vector <int> &nums)
    {
        if (i > j)
            return 0;
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        int maxi = INT_MIN;
        
        for (int index = i; index <=j; index++)
        {
            int coins = nums[i - 1] * nums[index] * nums[j + 1] + func (i, index - 1, dp, nums) + func (index + 1, j, dp, nums);
            
            maxi = max (maxi, coins);
        }
        
        return dp[i][j] = maxi;
    }
    
    int maxCoins(vector<int>& nums) {
        
        int size = nums.size();
        nums.emplace_back(1);
        nums.emplace(nums.begin(), 1);
        
        vector <vector <int>> dp (size + 1, vector <int> (size + 1, -1));
        
        return func (1, size, dp, nums);
        
    }
};


//Solved by Tabulation Method

class Solution {
public:
    
    int func (int i, int j, vector <vector<int>> &dp, vector <int> &nums)
    {
        if (i > j)
            return 0;
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        int maxi = INT_MIN;
        
        for (int index = i; index <=j; index++)
        {
            int coins = nums[i - 1] * nums[index] * nums[j + 1] + func (i, index - 1, dp, nums) + func (index + 1, j, dp, nums);
            
            maxi = max (maxi, coins);
        }
        
        return dp[i][j] = maxi;
    }
    
    int maxCoins(vector<int>& nums) {
        
        int size = nums.size();
        nums.emplace_back(1);
        nums.emplace(nums.begin(), 1);
        
        vector <vector <int>> dp (size + 2, vector <int> (size + 2, 0));
        
        for (int i = size; i >= 1; i--)
        {
            for (int j = i; j <= size; j++)
            {
                int maxi = INT_MIN;
                
                for (int index = i; index <= j; index++)
                {
                    int coins = nums[i - 1] * nums[index] * nums[j + 1] + dp[i][index - 1] + dp[index + 1][j];
                    
                    maxi = max (maxi, coins);
                }
                
                dp[i][j] = maxi;
            }
        }
        
        return dp[1][size];
        
    }
};