// Problem Link :- https://leetcode.com/problems/combination-sum-ii/

// Solved by Backtracking
// Time Complexity :- O(2^n)
// Space Complexity :- O(n)

class Solution {
public:

    void solve (int index, int &n, int target, vector<int> &ds, vector<vector<int>> &combinations, vector<int>& candidates)
    {
        if (target <= 0 || index == n)
        {
            if (target == 0)
                combinations.emplace_back(ds);

            return;
        }

        ds.emplace_back(candidates[index]);
        solve (index + 1, n, target - candidates[index], ds, combinations, candidates);
        ds.pop_back();

        while (index + 1 < n && candidates[index] == candidates[index + 1])
            index++;

        solve (index + 1, n, target, ds, combinations, candidates);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        int n = candidates.size();
        sort (candidates.begin(), candidates.end());

        vector<vector<int>> combinations;
        vector<int> ds;

        solve (0, n, target, ds, combinations, candidates);

        return combinations;
    }
};



class Solution {
public:
    
    void findCombinations2(int index, int target, vector <int> &candidates, vector<vector <int>> &ans, vector <int> &ds)
    {
        if (target == 0)
        {
            ans.emplace_back(ds);
            return;
        }
        
        for (int i = index; i<candidates.size(); i++)
        {
            if (i > index && candidates[i] == candidates[i-1])
                continue;
            
            if (candidates[i] > target)
                break;
            
            ds.emplace_back(candidates[i]);
            findCombinations2(i + 1, target - candidates[i], candidates, ans, ds);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort (candidates.begin(), candidates.end());
        vector<vector <int>> ans;
        vector <int> ds;
        findCombinations2(0, target, candidates, ans, ds);
        
        return ans;
    }
};
