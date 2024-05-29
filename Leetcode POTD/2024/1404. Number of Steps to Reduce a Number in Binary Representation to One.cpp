// Problem Link :- https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/

// Solved by Simulation
// Time Complexity :- O(n^2)
// Space Complexity :- O(1)

class Solution {
public:
    
    void divideByTwo(string &s) 
    { 
        s.pop_back(); 
    }

    void addOne(string &s) 
    {
        int i = s.length() - 1;

        while (i >= 0 && s[i] == '1') 
        {
            s[i] = '0';
            i--;
        }

        if (i < 0)
            s = '1' + s;
        
        else
            s[i] = '1';
    }

    int numSteps(string s) {

        int n = s.length(), operations = 0;
        
        while (n > 1) 
        {
            if (s.back() == '0')
                divideByTwo(s);
            
            else
                addOne(s);

            operations++;
            n = s.length();
        }

        return operations;
    }
};



// Solved by Greedy Approach
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int numSteps(string s) {
        
        int n = s.length(), operations = 0, carry = 0;
        
        for (int i = n - 1; i > 0; i--) 
        {
            if (((s[i] - '0') + carry) % 2) 
            {
                operations += 2;
                carry = 1;
            } 
            
            else
                operations++;
        }

        return operations + carry;
    }
};