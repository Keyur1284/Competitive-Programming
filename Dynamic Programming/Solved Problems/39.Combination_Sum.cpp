//Problem Link :- https://leetcode.com/problems/combination-sum/

class Solution {
public:
    
    void findCombinations(int index, int target, vector<int> &candidates, vector<vector<int>> &ans, vector<int> &vec)
    {
        if (index == candidates.size())
        {
            if (target == 0)
                ans.emplace_back(vec);
            
            return;
        }
        
        if (candidates[index] <= target)
        {
            vec.emplace_back(candidates[index]);
            findCombinations(index, target - candidates[index], candidates, ans, vec);
            vec.pop_back();
        }
        
        findCombinations(index+1, target, candidates, ans, vec);

    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      
        vector<vector<int>> ans;
        vector<int> vec;
        findCombinations(0, target, candidates, ans, vec);
        return ans;        
    }
};

