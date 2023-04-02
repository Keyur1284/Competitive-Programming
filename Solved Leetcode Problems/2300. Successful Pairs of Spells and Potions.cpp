// Problem Link :- https://leetcode.com/problems/successful-pairs-of-spells-and-potions/

// Time Complexity :- O((m+n)⋅logm); n -> spells.size(), m -> potions.size()
// Space Complexity :- O(m)

// Solved using Binary Search

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        int n = potions.size();
        sort(potions.begin(), potions.end());
        
        vector<int> ans;

        for (auto &it : spells)
        {
            long long mini = (success + it - 1)/it;
            int low = 0, high = n - 1, mid, index = n;

            while (low <= high)
            {
                mid = (low + high) >> 1;

                if (potions[mid] >= mini)
                {
                    high = mid - 1;
                    index = mid;
                }

                else 
                    low = mid + 1;
            }

            ans.emplace_back(n - index);
        }

        return ans;
    }
};


// Solved using inbuilt lower_bound function

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        int n = potions.size();
        sort(potions.begin(), potions.end());
        
        vector<int> ans;

        for (auto &it : spells)
        {
            long long mini = (success + it - 1)/it;
            int index = lower_bound(potions.begin(), potions.end(), mini) - potions.begin();

            ans.emplace_back(n - index);
        }

        return ans;
    }
};
