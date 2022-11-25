//Problem Link :- https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

//Solved by Memoization Method

class Solution {
public:
    
    int func (int i, int j, vector <vector <int>> &dp,vector<int>& cuts)
    {
        if (i > j)
            return 0;
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        int mini = INT_MAX;
        
        for (int index = i; index <= j; index++)
        {
            int cost = cuts[j + 1] - cuts[i - 1] + func (i, index - 1, dp, cuts) + func (index + 1, j, dp, cuts);
            mini = min (mini, cost);
        }
        
        return dp[i][j] = mini;
    }
    
    int minCost(int n, vector<int>& cuts) {
        
        int size = cuts.size();
        cuts.emplace_back(n);
        cuts.emplace(cuts.begin(), 0);
        
        sort (cuts.begin(), cuts.end());
        
        vector <vector <int>> dp(size + 1, vector <int> (size + 1, -1));
        
        return func (1, size, dp, cuts);
    }
};


//Solved by Tabulation Method

class Solution {
public:
    
    int func (int i, int j, vector <vector <int>> &dp,vector<int>& cuts)
    {
        if (i > j)
            return 0;
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        int mini = INT_MAX;
        
        for (int index = i; index <= j; index++)
        {
            int cost = cuts[j + 1] - cuts[i - 1] + func (i, index - 1, dp, cuts) + func (index + 1, j, dp, cuts);
            mini = min (mini, cost);
        }
        
        return dp[i][j] = mini;
    }
    
    int minCost(int n, vector<int>& cuts) {
        
        int size = cuts.size();
        cuts.emplace_back(n);
        cuts.emplace(cuts.begin(), 0);
        
        sort (cuts.begin(), cuts.end());
        
        vector <vector <int>> dp(size + 2, vector <int> (size + 2, 0));
        
        for (int i = size; i>=1; i--)
        {
            for (int j = i; j <= size; j++)
            {
                // if (i > j)           We can comment this out if we start the jth loop from i
                //     continue;
                
                int mini = INT_MAX;
        
                for (int index = i; index <= j; index++)
                {
                    int cost = cuts[j + 1] - cuts[i - 1] + dp[i][index - 1] + dp[index + 1][j];
                    mini = min (mini, cost);
                }

                dp[i][j] = mini;
            }
        }
        
        return dp[1][size];
    }
};