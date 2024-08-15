// Problem Link :- https://leetcode.com/problems/lemonade-change/

// Solved by Greedy Approach
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        int five = 0, ten = 0;

        for (auto &bill : bills)
        {
            if (bill == 5)
                five++;

            else if (bill == 10)
            {
                if (--five < 0)
                    return false;

                ten++;
            }

            else
            {
                if (ten == 0)
                {
                    five -= 3;

                    if (five < 0)
                        return false;
                }

                else
                {
                    if (--five < 0 || --ten < 0)
                        return false;
                }
            }
        }

        return true;
    }
};



class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        int fiveDollarBills = 0, tenDollarBills = 0;

        for (int customerBill : bills) 
        {
            if (customerBill == 5)
                fiveDollarBills++;
            
            else if (customerBill == 10) 
            {
                if (fiveDollarBills > 0) 
                {
                    fiveDollarBills--;
                    tenDollarBills++;
                } 
                
                else
                    return false;
            } 
            
            else 
            {
                if (tenDollarBills > 0 && fiveDollarBills > 0) 
                {
                    fiveDollarBills--;
                    tenDollarBills--;
                } 
                
                else if (fiveDollarBills >= 3)
                    fiveDollarBills -= 3;
                
                else
                    return false;
            }
        }

        return true;
    }
};