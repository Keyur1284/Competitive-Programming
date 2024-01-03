// Problem Link :- https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/

// Time Complexity :- O(nlogn)
// Space Complexity :- O(1)

class Solution {
public:
    double average(vector<int>& salary) {
        
        sort(salary.begin(), salary.end());
        double n = salary.size();

        double total = accumulate(salary.begin() + 1, salary.end() - 1, 0);

        double ans = total * 1.0 / (n - 2);

        return ans;
    }
};


// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    double average(vector<int>& salary) {
        
        double n = salary.size();

        double total = accumulate(salary.begin(), salary.end(), 0);
        double mini = *min_element(salary.begin(), salary.end());
        double maxi = *max_element(salary.begin(), salary.end());

        total -= (mini + maxi);

        double ans = total * 1.0 / (n - 2);

        return ans;
    }
};