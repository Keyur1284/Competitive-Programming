//Problem Link :- https://leetcode.com/problems/permutation-sequence/

class Solution {
public:
    string getPermutation(int n, int k) {
        vector <int> nums;
        int fact = 1;
        string ans = "";
        
        for (int i = 1; i<n; i++)
        {
            nums.emplace_back(i);
            fact *= i;
        }
        nums.emplace_back(n);
        
        k--;
        
        while (1)
        {
            ans += to_string(nums[k/fact]);
            nums.erase(nums.begin() + k/fact);
            
            if (nums.size() == 0)
                break;
            
            k %= fact;
            fact /= nums.size();
        }
        
        return ans;
    }
};