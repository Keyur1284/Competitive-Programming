// Problem Link :- https://leetcode.com/problems/longest-consecutive-sequence/

// Solved by sorting
// Time Complexity :- O(nlogn)
// Space Complexity :- O(1)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        int n = nums.size(), longest = 1, count = 1;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] - 1 == nums[i - 1])
                count++;
                
            else if (nums[i] != nums[i - 1])
                count = 1;

            longest = max(longest, count);
        }

        return min(longest, n);
    }
};


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();

        if (n == 0)
            return 0;

        sort (nums.begin(), nums.end());
        int maxStreak = 1, streak = 1;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] != nums[i - 1])
            {
                if (nums[i] == nums[i - 1] + 1)
                    streak++;

                else
                    streak = 1;
            }

            maxStreak = max(maxStreak, streak);
        }

        return maxStreak;
    }
};


// Solved by using unordered_set
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if (nums.empty())
            return 0;

        unordered_set <int> st;

        for (auto &it : nums)
            st.emplace(it);
        
        int longest = 1;

        for (auto &it : st)
        {
            if (st.find(it - 1) == st.end())
            {
                int num = it;
                int count = 1;

                while (st.find(num + 1) != st.end())
                {
                    num++;
                    count++;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};


// Solved by Union Find
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class DSU {

private:
    
    vector<int> parent, rank, size;

public:

    DSU (int n)
    {
        for (int i = 0; i <= n; i++)
        {
            parent.emplace_back(i);
            rank.emplace_back(0);
            size.emplace_back(1);
        }
    }

    int findPar (int node)
    {
        if (node == parent[node])
            return node;

        return parent[node] = findPar(parent[node]);
    }

    void UnionRank (int u, int v)
    {
        u = findPar(u);
        v = findPar(v);

        if (u == v)
            return;

        if (rank[u] < rank[v])
        {
            parent[u] = v;
        }

        else if (rank[u] > rank[v])
        {
            parent[v] = u;
        }

        else if (rank[u] == rank[v])
        {
            parent[v] = u;
            rank[u]++;
        }
    }

    void UnionSize (int u, int v)
    {
        u = findPar(u);
        v = findPar(v);

        if (u == v)
            return;

        if (size[u] < size[v])
        {
            parent[u] = v;
            size[v] += size[u];
        }

        else if (rank[u] >= rank[v])
        {
            parent[v] = u;
            size[u] += size[v];
        }
    }   
    
    int getSize (int u)
    {
        return size[u];
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();

        if (n == 0)
            return 0;

        DSU dsu(n - 1);
        unordered_map<int, int> mp;
        
        for (int i = 0; i < n; i++)
        {
            if (mp.find(nums[i]) != mp.end())
                continue;

            mp[nums[i]] = i;

            if (mp.find(nums[i] + 1) != mp.end())
                dsu.UnionSize (i, mp[nums[i] + 1]);

            if (mp.find(nums[i] - 1) != mp.end())
                dsu.UnionSize (i, mp[nums[i] - 1]);
        }

        int maxStreak = 1;

        for (int i = 0; i < n; i++)
        {
            if (dsu.findPar(i) == i)
                maxStreak = max (maxStreak, dsu.getSize(i));
        }

        return maxStreak;
    }
};