// Problem Link :- https://leetcode.com/problems/number-of-flowers-in-full-bloom/

// Solved by min heap
// Time Complexity :- O(nlogn + mlogm + mlogn)      // n = number of flowers
// Space Complexity :- O(n + m)     // m = number of people

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        
        int fools = flowers.size();
        sort (flowers.begin(), flowers.end());

        unordered_map<int, int> mp;
        vector<int> copy = people; 

        sort (people.begin(), people.end());

        priority_queue<int, vector<int>, greater<int>> pq;
        int i = 0;

        for (auto &it : people)
        {
            while(i < fools && flowers[i][0] <= it)
                pq.emplace(flowers[i++][1]);

            while (!pq.empty() && pq.top() < it)
                pq.pop();

            mp[it] = pq.size();
        }

        vector<int> ans;

        for (auto &it : copy)
            ans.emplace_back(mp[it]);

        return ans;
    }
};



// Solved by map
// Time Complexity :- O(nlogn + mlogn)      // n = number of flowers
// Space Complexity :- O(n)     // m = number of people

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        
        map<int, int> diff;
        diff[0] = 0;
        
        for (auto &it : flowers)
        {
            diff[it[0]]++;
            diff[it[1] + 1]--;
        }

        vector<int> pos, pref, ans;
        int bloom = 0;

        for (auto &it : diff)
        {
            pos.emplace_back(it.first);
            bloom += it.second;
            pref.emplace_back(bloom);
        }

        for (auto &it : people)
        {
            int i = upper_bound(pos.begin(), pos.end(), it) - pos.begin() - 1;
            ans.emplace_back(pref[i]);
        }

        return ans;
    }
};



// Solved by binary search on start time and end time
// Time Complexity :- O(nlogn + mlogn)      // n = number of flowers
// Space Complexity :- O(n)     // m = number of people

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        
        vector<int> born, die, ans;

        for (auto &it : flowers)
        {
            born.emplace_back(it[0]);
            die.emplace_back(it[1] + 1);
        }

        sort (born.begin(), born.end());
        sort (die.begin(), die.end());

        for (auto &it : people)
        {
            int i = upper_bound(born.begin(), born.end(), it) - born.begin();
            int j = upper_bound(die.begin(), die.end(), it) - die.begin();

            ans.emplace_back(i - j);
        }

        return ans;
    }
};