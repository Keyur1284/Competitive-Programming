// Problem Link :- https://leetcode.com/problems/evaluate-reverse-polish-notation/

// Solved using stack and unordered_map
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        unordered_map<string, function<int(int, int)>> op = {
            { "+" , [&] (int a, int b) { return a + b; } },
            { "-" , [&] (int a, int b) { return a - b; } },
            { "*" , [&] (int a, int b) { return a * b; } },
            { "/" , [&] (int a, int b) { return a / b; } }
        };
        
        stack<int> st;

        for (auto &k : tokens) 
        {
            if (!op.count(k))
                st.emplace(stoi(k));
            
            else 
            {
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();
                
                st.emplace(op[k](op1, op2));
            }
        }

        return st.top();
    }
};



// Solved using stack and switch case
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> st;
        
        for (auto &k : tokens) 
        {
            if (k == "+" || k == "-" || k == "*" || k == "/")
            {
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();
                
                switch(k[0])
                {
                    case '+':
                        st.emplace(op1 + op2);
                        break;
                    
                    case '-':
                        st.emplace(op1 - op2);
                        break;
                    
                    case '*':
                        st.emplace(op1 * op2);
                        break;
                    
                    case '/':
                        st.emplace(op1 / op2);
                        break;
                }
            }

            else
                st.emplace(stoi(k));
        }
        
        return st.top();
    }
};



// Solved by recursion
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:

    int evalRPN(vector<string>& tokens) {
        
        int n = tokens.size(), ind = n - 1;

        function<int()> eval = [&]() {
            
            auto &token = tokens[ind--];
            
            if (token == "+" || token == "-" || token == "*" || token == "/") 
            {
                int op2 = eval();
                int op1 = eval();
                
                if (token == "+") 
                    return op1 + op2;
                
                if (token == "-")
                    return op1 - op2;

                if (token == "*")
                    return op1 * op2;

                if (token == "/")
                    return op1 / op2;
            }
            
            return stoi(token);
        };

        return eval();
    }
};