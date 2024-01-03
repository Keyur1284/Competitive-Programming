// Problem Link :- https://leetcode.com/problems/asteroid-collision/

// Solved using stack
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        vector<int> ans;

        for (auto &it : asteroids)
        {
            bool flag = true;

            while (!ans.empty() && ans.back() > 0 && it < 0)
            {
                if (ans.back() < -it)
                {
                    ans.pop_back();
                    continue;
                }

                if (ans.back() == -it)
                    ans.pop_back();

                
                flag = false;
                break;
            } 

            if (flag)
                ans.emplace_back(it);
        }

        return ans;
    }
};