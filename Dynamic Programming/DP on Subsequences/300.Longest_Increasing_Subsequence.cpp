//Problem Link :- https://leetcode.com/problems/longest-increasing-subsequence/

//Solved by Memoization Method

class Solution {
public:
    
    int func (int index, int prev, vector <vector <int>> &dp, vector<int>& nums)
    {
        if (index == nums.size())
            return 0;
        
        if (dp[index][prev + 1] != -1)
            return dp[index][prev + 1];
        
        int notTake = 0 + func (index + 1, prev, dp, nums);
        int take = INT_MIN;
        
        if (prev == -1 || nums[index] > nums[prev])
            take = 1 + func (index + 1, index, dp, nums);
        
        return dp[index][prev + 1] = max (take, notTake);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        
        vector <vector <int>> dp (n, vector <int> (n + 1, -1));
        
        return func (0, -1, dp, nums);
        
    }
};


//Solved by Tabulation Method

class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        
        vector <vector <int>> dp (n + 1, vector <int> (n + 1, 0));
        
        for (int prev = -1; prev <= n - 1; prev++)      //  This initialization can be omitted as we have already assigned 0 to all
            dp[n][prev + 1] = 0;
        
        for (int index = n - 1; index >= 0; index--)
        {
            for (int prev = index - 1; prev >= -1; prev--)
            {
                int notTake = 0 + dp[index + 1][prev + 1];
                int take = INT_MIN;
                
                if (prev == -1 || nums[index] > nums[prev])
                    take = 1 + dp[index + 1][index + 1];
                
                dp[index][prev + 1] = max (take, notTake);
            }
        }
        
        return dp[0][-1 + 1];
        
    }
};


//Solved by Tabulation Method (Less Space Optimized) (Using 2 rows)

class Solution {
public:
   
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        
        vector <int> dp (n + 1, 0);
        
        for (int prev = -1; prev <= n - 1; prev++)      //  This initialization can be omitted as we have already assigned 0 to all
            dp[prev + 1] = 0;
        
        for (int index = n - 1; index >= 0; index--)
        {
            vector <int> temp (n + 1, 0);
            
            for (int prev = index - 1; prev >= -1; prev--)
            {
                int notTake = 0 + dp[prev + 1];
                int take = INT_MIN;
                
                if (prev == -1 || nums[index] > nums[prev])
                    take = 1 + dp[index + 1];
                
                temp[prev + 1] = max (take, notTake);
            }
            
            dp = temp;
        }
        
        return dp[-1 + 1];
        
    }
};


//Solved by Tabulation Method (Best Space Optimized) (Using 1 row)

class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        
        vector <int> dp (n + 1, 0);
        
        for (int prev = -1; prev <= n - 1; prev++)      //  This initialization can be omitted as we have already assigned 0 to all
            dp[prev + 1] = 0;
        
        for (int index = n - 1; index >= 0; index--)
        {            
            for (int prev = index - 1; prev >= -1; prev--)
            {
                int notTake = 0 + dp[prev + 1];
                int take = INT_MIN;
                
                if (prev == -1 || nums[index] > nums[prev])
                    take = 1 + dp[index + 1];
                
                dp[prev + 1] = max (take, notTake);
            }
        }
        
        return dp[-1 + 1];
        
    }
};


//Another approach  (This is used if we want to print the longest increasing subsequence)

//Solved by Tabulation Method (Best Space Optimized) (Using 1 row)

class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size(), maxi = INT_MIN;
        
        vector <int> dp (n, 1);
        
        for (int index = 0; index < n; index++)
        {            
            for (int prev = 0; prev < index; prev++)
            {
                if (nums[prev] < nums[index])
                    dp[index] = max (1 + dp[prev], dp[index]);
            }
            
            maxi = max (maxi, dp[index]);
        }
        
        return maxi;
    }
};


//Solved by using Binary Search (Fastest Solution)
//We can use this method only if we want to get the length of the longest increasing subsequence
//But we cannot use this when we want to print the longest increasing subsequence

class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size(), maxi = INT_MIN;
        
        vector <int> temp;
        temp.emplace_back(nums[0]);
        int len = 1;
        
        for (int index = 1; index < n; index++)
        {            
            if (nums[index] > temp.back())
            {
                temp.emplace_back(nums[index]);
                len++;
            }
            
            else
            {
                auto it = lower_bound(temp.begin(), temp.end(), nums[index]) - temp.begin();
                temp[it] = nums[index];
                    
            }
        }
        
        return temp.size();     //We can also return len in place of temp.size()
        
    }
};


//Code for printing the longest increasing subsequence

class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size(), maxi = INT_MIN, last = 0;
        
        vector <int> dp (n, 1), hash(n);
        
        for (int index = 0; index < n; index++)
        {
            hash[index] = index;
            
            for (int prev = 0; prev < index; prev++)
            {
                if (nums[prev] < nums[index] && 1 + dp[prev] > dp[index])
                {
                    dp[index] = 1 + dp[prev];
                    hash[index] = prev;
                }
            }
            
            if (dp[index] > maxi)
            {
                maxi = dp[index];
                last = index;
            }
        }
        
        vector <int> list;
        list.emplace_back(nums[last]);
        
        while (last != hash[last])
        {
            last = hash[last];
            list.emplace_back(nums[last]);
        }
        
        reverse (list.begin(), list.end());
        
        for (auto it : list)
            cout << it << " ";
        
        cout << endl;
        
        return maxi;
    }
};


//Another approach

class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size(), maxi = INT_MIN, last = 0;
        
        vector <int> dp (n, 1);
        
        for (int index = 0; index < n; index++)
        {            
            for (int prev = 0; prev < index; prev++)
            {
                if (nums[prev] < nums[index])
                    dp[index] = max (1 + dp[prev], dp[index]);
            }
            
            if (dp[index] > maxi)
            {
                maxi = dp[index];
                last = index;
            }
        }
        
        int temp = maxi + 1, j = maxi - 1;
        
        vector <int> list(maxi);
  
        for (int i = last; i >= 0; i--)
        {
            if (dp[i] + 1 == temp)
            {
                temp = dp[i];
                list[j--] = nums[i];
            }
        }
        
        for (auto it : list)
            cout << it << " ";
        
        cout << endl;
        
        return maxi;
    }
};