// Problem Link :- https://leetcode.com/problems/crawler-log-folder/

// Solved using stack
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int minOperations(vector<string>& logs) {
        
        stack<string> st;

        for (auto &log : logs)
        {
            if (log == "../")
            {
                if (!st.empty())
                    st.pop();
            }

            else if (log != "./")
                st.emplace(log);
        }

        return st.size();
    }
};



// Solved using counter
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int minOperations(vector<string>& logs) {
        
        int folderDepth = 0;

        for (auto &currentOperation : logs) 
        {
            if (currentOperation == "../")
                folderDepth = max(0, folderDepth - 1);

            else if (currentOperation != "./")
                folderDepth++;
        }

        return folderDepth;
    }
};