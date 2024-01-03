// Problem Link :- https://leetcode.com/problems/profitable-schemes/

// Time Complexity :- O(n*m*k) , m -> group.size(), and k -> minProfit
// Space Complexity :- O(n*m*k)

// Solved by Memoization Method

class Solution {
public:

    int MOD = 1e9 + 7;

    int func (int index, int count, int benefit, vector<vector<vector<int>>> &dp, int n, int minProfit, vector<int>& group, vector<int>& profit)
    {
        if (index == group.size())
            return benefit == minProfit;

        if (dp[index][count][benefit] != -1)
            return dp[index][count][benefit];

        int notTake = func(index + 1, count, benefit, dp, n, minProfit, group, profit);
        int take = 0;

        if (count + group[index] <= n)
            take = func(index + 1, count + group[index], min(benefit + profit[index], minProfit), dp, n, minProfit, group, profit);

        return dp[index][count][benefit] = (notTake % MOD + take % MOD) % MOD;
    }

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        
        int size = group.size();
        vector<vector<vector<int>>> dp (size, vector<vector<int>> (n + 1, vector<int> (minProfit + 1, -1)));

        return func (0, 0, 0, dp, n, minProfit, group, profit);
    }
};

class Solution {
public:

    int MOD = 1e9 + 7;

    int func (int index, int count, int benefit, vector<vector<vector<int>>> &dp, int n, int minProfit, vector<int>& group, vector<int>& profit)
    {
        if (index == 0)
        {
            if (count + group[index] <= n)
                return (benefit + profit[index] >= minProfit) + (benefit == minProfit);

            return benefit == minProfit;
        }

        if (dp[index][count][benefit] != -1)
            return dp[index][count][benefit];

        int notTake = func(index - 1, count, benefit, dp, n, minProfit, group, profit);
        int take = 0;

        if (count + group[index] <= n)
            take = func(index - 1, count + group[index], min(benefit + profit[index], minProfit), dp, n, minProfit, group, profit);

        return dp[index][count][benefit] = (notTake % MOD + take % MOD) % MOD;
    }

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        
        int size = group.size();
        vector<vector<vector<int>>> dp (size, vector<vector<int>> (n + 1, vector<int> (minProfit + 1, -1)));

        return func (size - 1, 0, 0, dp, n, minProfit, group, profit);
    }
};


// Solved by Tabulation Method

class Solution {
public:

    int MOD = 1e9 + 7;

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        
        int size = group.size();
        vector<vector<vector<int>>> dp (size + 1, vector<vector<int>> (n + 1, vector<int> (minProfit + 1, 0)));

        for (int index = size; index >= 0; index--)
        {
            for (int count = 0; count <= n; count++)
            {
                for (int benefit = 0; benefit <= minProfit; benefit++)
                {
                    if (index == size)
                    {
                        dp[index][count][benefit] = (benefit == minProfit);
                        continue;
                    }

                    int notTake = dp[index + 1][count][benefit];
                    int take = 0;

                    if (count + group[index] <= n)
                        take = dp[index + 1][count + group[index]][min(benefit + profit[index], minProfit)];

                    dp[index][count][benefit] = (notTake % MOD + take % MOD) % MOD;
                }
            }
        }

        return dp[0][0][0];
    }
};

class Solution {
public:

    int MOD = 1e9 + 7;

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        
        int size = group.size();
        vector<vector<vector<int>>> dp (size, vector<vector<int>> (n + 1, vector<int> (minProfit + 1, 0)));

        for (int index = 0; index < size; index++)
        {
            for (int count = 0; count <= n; count++)
            {
                for (int benefit = 0; benefit <= minProfit; benefit++)
                {
                    if (index == 0)
                    {
                        if (count + group[index] <= n)
                            dp[index][count][benefit] = (benefit + profit[index] >= minProfit);

                    
                        dp[index][count][benefit] += (benefit == minProfit);
                        
                        continue;
                    }

                    int notTake = dp[index - 1][count][benefit];
                    int take = 0;

                    if (count + group[index] <= n)
                        take = dp[index - 1][count + group[index]][min(benefit + profit[index], minProfit)];

                    dp[index][count][benefit] = (notTake % MOD + take % MOD) % MOD;
                }
            }
        }

        return dp[size - 1][0][0];
    }
};


// Solved by Tabulation Method (Space Optimized)

class Solution {
public:

    int MOD = 1e9 + 7;

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        
        int size = group.size();
        vector<vector<int>> dp (n + 1, vector<int> (minProfit + 1, 0));

        for (int index = size; index >= 0; index--)
        {
            vector<vector<int>> temp (n + 1, vector<int> (minProfit + 1, 0));

            for (int count = 0; count <= n; count++)
            {
                for (int benefit = 0; benefit <= minProfit; benefit++)
                {
                    if (index == size)
                    {
                        temp[count][benefit] = (benefit == minProfit);
                        continue;
                    }

                    int notTake = dp[count][benefit];
                    int take = 0;

                    if (count + group[index] <= n)
                        take = dp[count + group[index]][min(benefit + profit[index], minProfit)];

                    temp[count][benefit] = (notTake % MOD + take % MOD) % MOD;
                }
            }

            dp = temp;
        }

        return dp[0][0];
    }
};

class Solution {
public:

    int MOD = 1e9 + 7;

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        
        int size = group.size();
        vector<vector<int>> dp (n + 1, vector<int> (minProfit + 1, 0));

        for (int index = 0; index < size; index++)
        {
            vector<vector<int>> temp (n + 1, vector<int> (minProfit + 1, 0));

            for (int count = 0; count <= n; count++)
            {
                for (int benefit = 0; benefit <= minProfit; benefit++)
                {
                    if (index == 0)
                    {
                        if (count + group[index] <= n)
                            temp[count][benefit] = (benefit + profit[index] >= minProfit);

                    
                        temp[count][benefit] += (benefit == minProfit);

                        continue;
                    }

                    int notTake = dp[count][benefit];
                    int take = 0;

                    if (count + group[index] <= n)
                        take = dp[count + group[index]][min(benefit + profit[index], minProfit)];

                    temp[count][benefit] = (notTake % MOD + take % MOD) % MOD;
                }
            }

            dp = temp;
        }

        return dp[0][0];
    }
};