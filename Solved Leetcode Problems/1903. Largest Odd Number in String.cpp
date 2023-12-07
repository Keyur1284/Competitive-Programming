// Problem Link :- https://leetcode.com/problems/largest-odd-number-in-string/

// Solved by reverse iteration
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    string largestOddNumber(string num) {
        
        int n = num.length();
        string ans = num;

        for (int i = n - 1; i >= 0; i--)
        {
            if ((num[i] - '0') & 1)
                break;

            ans.pop_back();
        }

        return ans;
    }
};



// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    string largestOddNumber(string num) {
        
        int n = num.length();

        for (int i = n - 1; i >= 0; i--)
        {
            if ((num[i] - '0') & 1)
                break;

            num.pop_back();
        }

        return num;
    }
};