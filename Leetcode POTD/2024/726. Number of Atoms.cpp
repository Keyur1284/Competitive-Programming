// Problem Link :- https://leetcode.com/problems/number-of-atoms/

// Solved using stack and map
// Time Complexity :- O(n^2)
// Space Complexity :- O(n)

class Solution {
public:
    string countOfAtoms(string formula) {
        
        int n = formula.length();
        stack<pair<string, int>> st;

        for (int i = 0; i < n; i++)
        {
            char ch = formula[i];

            if (isupper(ch))
            {
                string element = "", numString = "";
                element += ch;
                int j = i + 1;

                while(j < n && islower(formula[j]))
                    element += formula[j++];

                while(j < n && isdigit(formula[j]))
                    numString += formula[j++];

                if (numString == "")
                    numString = "1";

                int numVal = stoi(numString);
                st.emplace(element, numVal);
                i = j - 1;
            }

            else if (ch == '(')
                st.emplace("(", -1);

            else
            {
                string numString = "";
                int j = i + 1;

                while(j < n && isdigit(formula[j]))
                    numString += formula[j++];

                if (numString == "")
                    numString = "1";
                
                int numVal = stoi(numString);
                stack<pair<string, int>> temp;
                pair<string, int> openBracket = {"(", -1};
                
                while(st.top() != openBracket)
                {
                    auto it = st.top();
                    st.pop();
                    it.second *= numVal;
                    temp.emplace(it);
                }

                st.pop();

                while(!temp.empty())
                {
                    st.emplace(temp.top());
                    temp.pop();
                }

                i = j - 1;
            }
        }

        map<string, int> mp;

        while(!st.empty())
        {
            auto it = st.top();
            st.pop();
            mp[it.first] += it.second;
        }

        string ans;

        for (auto &it : mp)
        {
            string element = it.first, count = (it.second == 1) ? "" : to_string(it.second);
            ans += element + count;
        }

        return ans;
    }
};



// Solved by Preprocessing multiplying factor in reverse order
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:
    string countOfAtoms(string formula) {
        
        int n = formula.length(), prod = 1;
        stack<int> nums;
        vector<int> mul(n, 1);

        for (int i = n - 1; i >= 0; i--)
        {
            char ch = formula[i];

            if (ch == ')')
            {
                string numString = "";
                int j = i + 1;

                while (j < n && isdigit(formula[j]))
                    numString += formula[j++];

                if (numString == "")
                    numString = "1";

                int numVal = stoi(numString);
                prod *= numVal;
                nums.emplace(numVal);
            }

            else if (ch == '(')
            {
                prod /= nums.top();
                nums.pop();
            }

            mul[i] = prod;
        }

        map<string, int> mp;

        for (int i = 0; i < n; i++)
        {
            char ch = formula[i];

            if (isupper(ch))
            {
                string element = "", numString = "";
                element += ch;
                int j = i + 1;

                while(j < n && islower(formula[j]))
                    element += formula[j++];

                while(j < n && isdigit(formula[j]))
                    numString += formula[j++];

                if (numString == "")
                    numString = "1";

                int numVal = stoi(numString);
                mp[element] += mul[i] * numVal; 
                i = j - 1;
            }
        }

        string ans;

        for (auto &it : mp)
        {
            string element = it.first, count = (it.second == 1) ? "" : to_string(it.second);
            ans += element + count;
        }

        return ans;
    }
};