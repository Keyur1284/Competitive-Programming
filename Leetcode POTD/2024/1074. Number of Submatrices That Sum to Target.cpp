// Problem Link :- https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/

// Solved by 2D prefix sum
// Time Complexity :- O(n^2 * m^2)
// Space Complexity :- O(n * m)

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> pref(n + 1, vector<int> (m + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }

        int count = 0;

        for (int sr = 1; sr <= n; sr++)
        {
            for (int sc = 1; sc <= m; sc++)
            {
                for (int er = sr; er <= n; er++)
                {
                    for (int ec = sc; ec <= m; ec++)
                    {
                        int sum = pref[er][ec] - pref[sr - 1][ec] - pref[er][sc - 1] + pref[sr - 1][sc - 1];
                        count += (sum == target);
                    }
                }
            }
        }
        
        return count;
    }
};



// Solved by 2D prefix sum and hashing
// Time Complexity :- O(n^2 * m)
// Space Complexity :- O(n * m)

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> pref(n + 1, vector<int> (m + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }

        int count = 0;

        for (int sr = 1; sr <= n; sr++)
        {
            for (int er = sr; er <= n; er++)
            {
                unordered_map<int, int> mp;
                mp[0]++;

                for (int col = 1; col <= m; col++)
                {
                    int sum = pref[er][col] - pref[sr - 1][col];
                    int need = sum - target;

                    if (mp.count(need))
                        count += mp[need];

                    mp[sum]++;
                }
            }
        }
        
        return count;
    }
};



// Time Complexity :- O(m^2 * n)
// Space Complexity :- O(n * m)

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> pref(n + 1, vector<int> (m + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }

        int count = 0;

        for (int sc = 1; sc <= m; sc++)
        {
            for (int ec = sc; ec <= m; ec++)
            {
                unordered_map<int, int> mp;
                mp[0]++;

                for (int row = 1; row <= n; row++)
                {
                    int sum = pref[row][ec] - pref[row][sc - 1];
                    int need = sum - target;

                    if (mp.count(need))
                        count += mp[need];

                    mp[sum]++;
                }
            }
        }
        
        return count;
    }
};



// Solved by row wise prefix sum and hashing
// Time Complexity :- O(m^2 * n)
// Space Complexity :- O(n * m)

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size(), m = matrix[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                matrix[i][j] += matrix[i][j - 1];
            }
        }

        int count = 0;

        for (int sc = 0; sc < m; sc++)
        {
            for (int ec = sc; ec < m; ec++)
            {
                unordered_map<int, int> mp;
                mp[0]++;
                int sum = 0;

                for (int row = 0; row < n; row++)
                {
                    sum += matrix[row][ec] - (sc > 0 ? matrix[row][sc - 1] : 0);
                    int need = sum - target;

                    if (mp.count(need))
                        count += mp[need];

                    mp[sum]++;
                }
            }
        }
        
        return count;
    }
};