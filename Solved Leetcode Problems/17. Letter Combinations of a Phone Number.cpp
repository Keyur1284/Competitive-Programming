// Problem Link :- https://leetcode.com/problems/letter-combinations-of-a-phone-number/

// Solved by Backtracking
// Time Complexity :- O(n * 4^n)
// Space Complexity :- O(4^n)

class Solution {
public:

    void solve (int index, int &n, string &path, vector<char> mp[], vector<string> &combinations, string &digits)
    {
        if (index == n)
        {
            combinations.emplace_back(path);
            return;
        }

        int num = digits[index] - '0';

        for (auto &k : mp[num])
        {
            path += k;
            solve (index + 1, n, path, mp, combinations, digits);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string &digits) {
        
        int n = digits.size();
        vector<string> combinations;

        if (n == 0)
            return combinations;

        vector<char> mp[10];
        char k = 'a';

        for (int i = 2; i <= 9; i++, k += 3)
        {
            mp[i].emplace_back(k);
            mp[i].emplace_back(k + 1);
            mp[i].emplace_back(k + 2);

            if (i == 7 || i == 9)
                mp[i].emplace_back(++k + 2);
        }

        string path = "";
        
        solve (0, n, path, mp, combinations, digits);

        return combinations;
    }
};