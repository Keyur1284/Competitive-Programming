// Problem Link :- https://leetcode.com/problems/validate-stack-sequences/

// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        stack<int> st;
        int n = pushed.size();

        int j = 0;

        for (auto &num : pushed)
        {
            st.emplace(num);
            
            while (!st.empty() && j < n && st.top() == popped[j])
            {
                st.pop();
                j++;
            }
        }

        return st.empty();
    }
};


// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        stack<int> st;
        int n = pushed.size();

        int i = 0, j = 0;

        for (auto &num : pushed)
        {
            pushed[i++] = num;
            
            while (i > 0 && j < n && pushed[i - 1] == popped[j])
            {
                i--;
                j++;
            }
        }

        return (i == 0);
    }
};