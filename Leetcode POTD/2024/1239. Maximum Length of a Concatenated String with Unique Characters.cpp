// Problem Link :- https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

// Solved by Backtracking
// Time Complexity :- O(2^n)
// Space Complexity :- O(n)

class Solution {
public:

    int solve (int index, int n, unordered_set<char> &st, vector<string>& arr)
    {
        if (index == n)
            return 0;

        bool take = true;
        unordered_set<char> temp(arr[index].begin(), arr[index].end());

        if (temp.size() != arr[index].size())
            take = false;

        else
        {
            for (auto &it : arr[index])
            {
                if (st.find(it) != st.end())
                {
                    take = false;
                    break;
                }
            }
        }
        
        int taken = 0, notTake = 0;

        if (take)
        {
            for (auto &it : arr[index])
            {
                st.emplace(it);
            }

            taken += arr[index].size() + solve (index + 1, n, st,arr);

            for (auto &it : arr[index])
            {
                st.erase(it);
            }
        }

        notTake = solve (index + 1, n, st,arr);

        return max(taken, notTake);
    }

    int maxLength(vector<string>& arr) {
        
        int n = arr.size();
        unordered_set<char> st;

        return solve (0, n, st, arr);
    }
};