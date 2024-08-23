// Problem Link :- https://leetcode.com/problems/fraction-addition-and-subtraction/

// Solved by traversing
// Time Complexity :- O(n)
// Space Complexity :- O(log(min(a, b)))

class Solution {
public:
    string fractionAddition(string expression) {
        
        int n = expression.length(), num = 0, denom = 1, i = 0;
        while (i < n) 
        {
            int currNum = 0, currDenom = 0;
            bool isNegative = false;

            if (expression[i] == '-' || expression[i] == '+') 
                isNegative = (expression[i++] == '-');

            while (isdigit(expression[i])) 
            {
                int digit = expression[i] - '0';
                currNum = currNum * 10 + digit;
                i++;
            }

            if (isNegative) currNum *= -1;

            i++;

            while (i < n && isdigit(expression[i])) 
            {
                int digit = expression[i] - '0';
                currDenom = currDenom * 10 + digit;
                i++;
            }

            num = num * currDenom + currNum * denom;
            denom = denom * currDenom;
        }

        int gcd = abs(__gcd(num, denom));

        num /= gcd;
        denom /= gcd;

        return to_string(num) + "/" + to_string(denom);
    }
};