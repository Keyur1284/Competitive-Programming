// Problem Link :- https://leetcode.com/problems/sum-of-subarray-minimums/

// Solved by Sorting and Recursion
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int n = arr.size();
        vector<pair<int, int>> minOrder;

        for (int i = 0; i < n; i++)
            minOrder.emplace_back(arr[i], i);

        long ans = 0, MOD = 1e9 + 7;
        
        function<void(int, int, int)> solve = [&](int low, int high, int curr)
        {
            if (low > high)
                return;

            int next = minOrder[curr++].second;

            while (low > next || high < next)
                next = minOrder[curr++].second;

            int left = next - low + 1, right = high - next + 1;
            ans = (ans + 1LL * arr[next] * left * right) % MOD;

            solve(low, next - 1, curr);
            solve(next + 1, high, curr);
        };

        sort(minOrder.begin(), minOrder.end());
        solve(0, n - 1, 0);

        return ans;
    }
};



// Solved using Monotonic Stack
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<pair<int, int>> st;

        for (int i = 0; i < n; i++)
        {
            int count = 1;

            while (!st.empty() && st.top().first > arr[i])
            {
                count += st.top().second;
                st.pop();
            }

            st.emplace(arr[i], count);
            left[i] = count;
        }

        while (!st.empty())
            st.pop();

        for (int i = n - 1; i >= 0; i--)
        {
            int count = 1;

            while (!st.empty() && st.top().first >= arr[i])
            {
                count += st.top().second;
                st.pop();
            }

            st.emplace(arr[i], count);
            right[i] = count;
        }

        long long ans = 0, MOD = 1e9 + 7;

        for (int i = 0; i < n; i++)
        {
            ans = (ans + 1LL * arr[i] * left[i] * right[i]) % MOD;
        }

        return ans;
    }
};



class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> ple, nle;

        for (int i = 0; i < n; i++)
        {
            left[i] = i + 1;
            right[i] = n - i;
        }

        for (int i = 0; i < n; i++)
        {
            while (!ple.empty() && arr[ple.top()] > arr[i])
                ple.pop();

            left[i] = (ple.empty())? i + 1 : i - ple.top();

            while (!nle.empty() && arr[nle.top()] > arr[i])
            {
                int ind = nle.top();
                nle.pop();
                right[ind] = i - ind;
            }  

            nle.emplace(i);
            ple.emplace(i);
        }

        long ans = 0, MOD = 1e9 + 7;

        for (int i = 0; i < n; i++)
        {
            ans = (ans + 1LL * arr[i] * left[i] * right[i]) % MOD;
        }

        return ans;
    }
};