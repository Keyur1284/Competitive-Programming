// Problem Link :- https://leetcode.com/problems/xor-queries-of-a-subarray/

// Solved by prefix xor
// Time Complexity :- O(n + q)
// Space Complexity :- O(n)

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        int n = arr.size();
        vector<int> prefXor(n, 0);
        prefXor[0] = arr[0];

        for (int i = 1; i < n; i++)
            prefXor[i] = prefXor[i - 1] ^ arr[i];

        int q = queries.size();
        vector<int> answer(q);

        for (int i = 0; i < q; i++)
        {
            int left = queries[i][0], right = queries[i][1];
            answer[i] = (left - 1 >= 0 ? prefXor[left - 1] : 0) ^ prefXor[right];
        }

        return answer;
    }
};



class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        int n = arr.size();
        vector<int> prefXor(n + 1, 0);

        for (int i = 0; i < n; i++)
            prefXor[i + 1] = prefXor[i] ^ arr[i];

        int q = queries.size();
        vector<int> answer(q);

        for (int i = 0; i < q; i++)
        {
            int left = queries[i][0], right = queries[i][1];
            answer[i] = prefXor[left + 1 - 1] ^ prefXor[right + 1];
        }

        return answer;
    }
};