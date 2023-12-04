// Problem Link :- https://leetcode.com/problems/largest-3-same-digit-number-in-string/

// Solved by Brute Force Approach
// Time Complexity :- O(9 * n)
// Space Complexity :- O(1)

class Solution {
    
    vector<string> sameDigitNumbers = {"999", "888", "777", "666", "555", "444", "333", "222", "111", "000"};

    bool contains(string sameDigitNumber, string num) 
    {
        int n = num.size();

        for (int index = 0; index <= n - 3; index++) 
        {
            if (num[index] == sameDigitNumber[0] && num[index + 1] == sameDigitNumber[1] && num[index + 2] == sameDigitNumber[2]) 
            {
                return true;
            }
        }
        return false;
    }

public:
    string largestGoodInteger(string num) {

        for (auto &sameDigitNumber : sameDigitNumbers) 
        {
            if (contains(sameDigitNumber, num))
                return sameDigitNumber;
        }

        return "";
    }
};



// Solved in One Pass
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    string largestGoodInteger(string num) {

        char maxDigit = '\0';
        int n = num.size();

        for (int index = 0; index <= n - 3; index++) 
        {
            if (num[index] == num[index + 1] && num[index] == num[index + 2])
                maxDigit = max(maxDigit, num[index]);
        }

        return maxDigit == '\0' ? "" : string(3, maxDigit);
    }
};