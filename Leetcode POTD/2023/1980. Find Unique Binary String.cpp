// Problem Link :- https://leetcode.com/problems/find-unique-binary-string/

// Solved by backtracking
// Time Complexity :- O(2^n)
// Space Complexity :- O(2^n)

class Solution {
public:

    void solve (int index, string &ans, string &curr, unordered_set<string> &st)
    {
        if (index == 0)
        {
            if (!st.count(curr))
                ans = curr;

            return;
        }

        curr += "0";
        solve (index - 1, ans, curr, st);
        curr.pop_back();

        curr += "1";
        solve (index - 1, ans, curr, st);
        curr.pop_back();
    }

    string findDifferentBinaryString(vector<string>& nums) {
        
        int n = nums.size();
        unordered_set<string> st(nums.begin(), nums.end());
        string ans = "", curr = "";

        solve(n, ans, curr, st);

        return ans;
    }
};



// Solved by optimised recursion
// Time Complexity :- O(n^2)
// Space Complexity :- O(n)

class Solution {
public:
    
    int n;
    unordered_set<string> numsSet;
    
    string generate (string curr) 
    {
        if (curr.size() == n) 
        {
            if (numsSet.find(curr) == numsSet.end())
                return curr;
            
            return "";
        }
        
        string addZero = generate(curr + "0");

        if (addZero.size() > 0)
            return addZero;
        
        return generate(curr + "1");
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        
        n = nums.size();
        
        for (string s : nums) 
        {
            numsSet.insert(s);
        }
        
        return generate("");
    }
};