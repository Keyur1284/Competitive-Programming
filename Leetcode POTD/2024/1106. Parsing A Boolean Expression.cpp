// Problem Link :- https://leetcode.com/problems/parsing-a-boolean-expression/

// Solved by String Manipulation
// Time Complexity :- O(n^2)
// Space Complexity :- O(n)

class Solution {
public:
    bool parseBoolExpr(string expression) {

        while (expression.length() > 1)
        {
            int start = expression.find_last_of("!&|");
            int end = expression.find(')', start);
            string subExpr = expression.substr(start, end - start + 1);
            char result = evaluateSubExpr(subExpr);
            expression.replace(start, end - start + 1, 1, result);
        }

        return expression[0] == 't';
    }

private:
    char evaluateSubExpr(const string &subExpr) {

        char op = subExpr[0];
        string values = subExpr.substr(2, subExpr.length() - 3);

        if (op == '!')
            return values[0] ^ 't' ^ 'f';

        if (op == '&')
            return values.find('f') != string::npos ? 'f' : 't';

        if (op == '|')
            return values.find('t') != string::npos ? 't' : 'f';

        return 'f';
    }
};



// Solved by Recursion
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    bool parseBoolExpr(string expression) {
        
        int index = 0;
        return evaluate(expression, index);
    }

private:
    bool evaluate(string &expr, int &index) {

        char currChar = expr[index++];

        if (currChar == 't')
            return true;

        if (currChar == 'f')
            return false;

        if (currChar == '!')
        {
            index++;
            bool result = !evaluate(expr, index);
            index++;
            return result;
        }

        vector<bool> values;
        index++;
        
        while (expr[index] != ')')
        {
            if (expr[index] != ',')
                values.push_back(evaluate(expr, index));
            
            else
                index++;
        }

        index++;

        if (currChar == '&')
        {
            for (bool v : values)
            {
                if (!v)
                    return false;
            }

            return true;
        }

        if (currChar == '|')
        {
            for (bool v : values)
            {
                if (v)
                    return true;
            }

            return false;
        }

        return false;
    }
};



// Solved using Stack
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    bool parseBoolExpr(string expression) {
        
        stack<char> st;

        for (char currChar : expression) 
        {
            if (currChar == ')') 
            {
                vector<char> values;

                while (st.top() != '(') 
                {
                    values.push_back(st.top());
                    st.pop();
                }
                
                st.pop();
                char op = st.top();
                st.pop();

                char result = evaluateSubExpr(op, values);
                st.push(result);
            } 
            
            else if (currChar != ',')
                st.push(currChar);
        }

        return st.top() == 't';
    }

private:

    char evaluateSubExpr(char op, vector<char>& values) {
        
        if (op == '!') 
            return values[0] == 't' ? 'f' : 't';

        if (op == '&') 
        {
            for (char value : values) 
            {
                if (value == 'f') 
                    return 'f';
            }

            return 't';
        }

        if (op == '|') 
        {
            for (char value : values) 
            {
                if (value == 't') 
                    return 't';
            }

            return 'f';
        }

        return 'f';
    }
};



class Solution {
public:
    bool parseBoolExpr(string expression) {
        
        stack<char> st;

        for (char currChar : expression) 
        {
            if (currChar == ',' || currChar == '(')
                continue;

            if (currChar == 't' || currChar == 'f' || currChar == '!' || currChar == '&' || currChar == '|')
                st.push(currChar);
            
            else if (currChar == ')') 
            {
                bool hasTrue = false, hasFalse = false;

                while (st.top() != '!' && st.top() != '&' && st.top() != '|') 
                {
                    char topValue = st.top();
                    st.pop();
                    
                    if (topValue == 't') 
                        hasTrue = true;
                    
                    if (topValue == 'f') 
                        hasFalse = true;
                }

                char op = st.top();
                st.pop();
                
                if (op == '!')
                    st.push(hasTrue ? 'f' : 't');
                
                else if (op == '&')
                    st.push(hasFalse ? 'f' : 't');
                
                else
                    st.push(hasTrue ? 't' : 'f');
            }
        }

        return st.top() == 't';
    }
};