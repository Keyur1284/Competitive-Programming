// Problem Link :- https://leetcode.com/problems/different-ways-to-add-parentheses/

// Solved by Recursion
// Time Complexity :- O(n * 2^n)
// Space Complexity :- O(2^n)

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        
        int n = expression.length();
        vector<int> ans;

        if (n == 0)
            return ans;

        if (n == 1 || n == 2 && isdigit(expression[0]))
        {
            ans.emplace_back(stoi(expression));
            return ans;
        }

        for (int i = 0; i < expression.length(); i++) 
        {
            char currentChar = expression[i];

            if (isdigit(currentChar)) 
                continue;

            vector<int> leftResults = diffWaysToCompute(expression.substr(0, i));
            vector<int> rightResults = diffWaysToCompute(expression.substr(i + 1));

            for (int leftValue : leftResults) 
            {
                for (int rightValue : rightResults) 
                {
                    int computedResult = 0;

                    switch (currentChar) 
                    {
                        case '+':
                            computedResult = leftValue + rightValue;
                            break;
                        case '-':
                            computedResult = leftValue - rightValue;
                            break;
                        case '*':
                            computedResult = leftValue * rightValue;
                            break;
                    }

                    ans.emplace_back(computedResult);
                }
            }
        }

        return ans;
    }
};