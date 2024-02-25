// Problem Link :- https://leetcode.com/problems/greatest-common-divisor-traversal/

// Solved by Sieve of Eratosthenes + DFS
// Time Complexity :- O(n * log(1e5))
// Space Complexity :- O(n + 1e5)

bool isComputed = false;
vector<int> spf;

class Solution {
public:

    void findSPF()
    {
        spf.resize(1e5 + 1);
        iota(spf.begin(), spf.end(), 0);

        for (int p = 2; p * p <= 1e5; p++)
        {
            if (spf[p] == p)
            {
                for (int k = p * p; k <= 1e5; k += p)
                    spf[k] = p;
            }
        }
    }

    vector<int> findPrimeFactors(int num)
    {
        vector<int> uniquePrimeFactors;
        unordered_set<int> primeFactors;

        while (num != 1)
        {
            primeFactors.emplace(spf[num]);
            num /= spf[num];
        }

        for (auto &it : primeFactors)
            uniquePrimeFactors.emplace_back(it);

        return uniquePrimeFactors;
    }

    bool canTraverseAllPairs(vector<int>& nums) {
        
        if (!isComputed)
        {
            findSPF();
            isComputed = true;
        }
        
        int n = nums.size();
        vector<vector<int>> indexToFactors(n);

        for (int index = 0; index < n; index++)
        {
            indexToFactors[index] = findPrimeFactors(nums[index]);
        }

        unordered_map<int, vector<int>> factorsToIndex;

        for (int index = 0; index < n; index++)
        {
            for (auto &primeNum : indexToFactors[index])
            {
                factorsToIndex[primeNum].emplace_back(index);
            }
        }   

        vector<int> adj[n];

        for (auto &factor : factorsToIndex)
        {
            auto indices = factor.second;
            int n = indices.size();

            if (n == 1)
                continue;

            for (int ind = 1; ind < n; ind++)
            {
                int u = indices[ind - 1], v = indices[ind];
                adj[u].emplace_back(v);
                adj[v].emplace_back(u);
            }
        }

        vector<bool> vis(n, false);
        int count = 0;

        function<void(int)> DFS = [&](int node) -> void {

            vis[node] = true;
            count++;

            for (auto &child : adj[node])
            {
                if (!vis[child])
                    DFS(child);
            }
        };

        DFS(0);

        return (count == n);
    }
};