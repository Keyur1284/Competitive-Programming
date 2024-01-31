// Problem Link :- https://leetcode.com/problems/daily-temperatures/

// Solved by brute force + binary search
// Time Complexity :- O(n * 100 *logn)
// Space Complexity :- O(n)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size();
        vector<int> answer(n, n + 1), ind[101];

        for (int i = 0; i < n; i++)
            ind[temperatures[i]].emplace_back(i);

        for (int i = 0; i < n; i++)
        {
            int temp = temperatures[i];

            for (int next = temp + 1; next <= 100; next++)
            {
                if (ind[next].size())
                {
                    auto nextDay = lower_bound(ind[next].begin(), ind[next].end(), i);

                    if (nextDay == ind[next].end())
                        continue;

                    answer[i] = min(answer[i], *nextDay - i);
                }

            }

            if (answer[i] == n + 1)
                answer[i] = 0;
        }

        return answer;
    }
};



// Solved using stack
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size();
        vector<int> answer(n);
        stack<pair<int, int>> st;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top().first <= temperatures[i])
                st.pop();

            answer[i] = (st.empty()) ? 0 : st.top().second - i;
            
            st.emplace(temperatures[i], i);
        }

        return answer;
    }
};



class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size();
        vector<int> answer(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && temperatures[st.top()] <= temperatures[i])
                st.pop();

            answer[i] = (st.empty()) ? 0 : st.top() - i;
            
            st.emplace(i);
        }

        return answer;
    }
};



// Solved in best optimized way
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size(), maxTemp = -1;
        vector<int> answer(n, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            if (temperatures[i] >= maxTemp)
            {
                maxTemp = temperatures[i];
                continue;
            }

            int days = 1;

            while (temperatures[i + days] <= temperatures[i])
                days += answer[i + days];

            answer[i] = days;
        }

        return answer;
    }
};