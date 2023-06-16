// Problem Link :- https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/

// Solved by DFS + Pascal's Triangle
// Time Complexity :- O(n^2)
// Space Complexity :- O(n^2)

class Solution {
public:

    long long MOD = 1e9 + 7;
    vector<vector<long long>> pascal;

    void preCompute (long long n)
    {
        for (int i = 0; i < n; i++)
        {
            int size = i + 1;
            vector<long long> row (size, 1LL);

            for (int j = 1; j < (size + 1)/2; j++)
            {
                row[j] = (pascal[i - 1][j - 1] + pascal[i - 1][j]) % MOD;
                row[i - j] = row[j];
            }

            pascal.emplace_back(row);
        }
    }

    long long DFS (vector<int> &arr)
    {
        long long n = arr.size();

        if (n <= 2)
            return 1;

        vector<int> left, right;

        for (long long i = 1; i < n; i++)
        {
            (arr[i] < arr[0]) ? left.emplace_back(arr[i]) : right.emplace_back(arr[i]);
        }

        long long leftSize = left.size();
        long long leftWays = DFS (left);
        long long rightWays = DFS (right);
        long long permute = pascal[n - 1][leftSize];

        long long totalWays = (((permute * leftWays) % MOD) * rightWays) % MOD;

        return totalWays;
    }

    int numOfWays(vector<int>& nums) {
        
        long long n = nums.size();

        preCompute(n);

        long long countWays = DFS (nums) % MOD;

        return countWays - 1;
    }
};



// Solved by DFS + Binary Exponentiation    (Optimized Solution)
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:

    long long MOD = 1e9 + 7;
    vector<long long> fact;

    long long mod_power (long long base, long long exp)
    {
        long long res = 1;

        while (exp)
        {
            if (exp & 1)
                res = (res * base) % MOD;

            exp /= 2;
            base = (base * base) % MOD;
        }

        return res;
    }

    long long mod_inverse (long long num)
    {
        return mod_power(num, MOD - 2);
    }

    void preCompute (long long n)
    {
        fact.resize(n);
        fact[0] = 1;

        for (long long i = 1; i < n; i++)
            fact[i] = (fact[i - 1] * i) % MOD;
    }

    long long nCr (long long n, long long r)
    {
        if (r > n)
            return 0;
    
        long long res = fact[n];
        res = (res * 1LL * mod_inverse(fact[r])) % MOD;
        res = (res * 1LL * mod_inverse(fact[n - r])) % MOD;

        return res;
    }

    long long DFS (vector<int> &arr)
    {
        long long n = arr.size();

        if (n <= 2)
            return 1;

        vector<int> left, right;

        for (long long i = 1; i < n; i++)
        {
            (arr[i] < arr[0]) ? left.emplace_back(arr[i]) : right.emplace_back(arr[i]);
        }

        long long leftSize = left.size();
        long long leftWays = DFS (left);
        long long rightWays = DFS (right);
        long long permute = nCr (n - 1, leftSize);

        long long totalWays = (((permute * leftWays) % MOD) * rightWays) % MOD;

        return totalWays;
    }

    int numOfWays(vector<int>& nums) {
        
        long long n = nums.size();

        preCompute(n);

        long long countWays = DFS (nums) % MOD;

        return countWays - 1;
    }
};
