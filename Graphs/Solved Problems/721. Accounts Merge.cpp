// Problem Link :- https://leetcode.com/problems/accounts-merge/

// Solved by Union Find
// Time Complexity :- O(N * K * log(N * K))
// Space Complexity :- O(N * K)

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
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        int n = accounts.size();
        DSU dsu(n - 1);
        
        unordered_map <string, int> mp;

        for (int i = 0; i < n; i++)
        {
            int m = accounts[i].size();

            for (int j = 1; j < m; j++)
            {
                string mail = accounts[i][j];

                if (mp.find(mail) == mp.end())
                    mp[mail] = i;

                else
                    dsu.UnionSize(i, mp[mail]);
            }
        }

        vector<string> mergedMails[n];

        for (auto &it : mp)
        {
            string mail = it.first;
            int index = dsu.findPar(it.second);

            mergedMails[index].emplace_back(mail);
        }

        vector<vector<string>> mergedAccounts;

        for (int index = 0; index < n; index++)
        {
            vector<string> mails = mergedMails[index];
            int m = mails.size();
            
            if (m > 0)
            {
                string owner = accounts[index][0];
                vector<string> user;
                user.emplace_back(owner);

                sort(mails.begin(), mails.end());

                for (auto &it : mails)
                    user.emplace_back(it);

                mergedAccounts.emplace_back(user);
            }
        }

        return mergedAccounts;
    }
};



// Solved by DFS

class Solution {
public:

    unordered_set<string> vis;
    unordered_map<string, vector<string>> adj;

    void DFS (string mail, vector<string> &user)
    {
        vis.emplace(mail);
        user.emplace_back(mail);

        for (auto &it : adj[mail])
        {
            if (vis.find(it) == vis.end())
                DFS (it, user);
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        for (auto &it : accounts)
        {
            int m = it.size();
            string first = it[1];

            for (int j = 2; j < m; j++)
            {
                string mail = it[j];

                adj[first].emplace_back(mail);
                adj[mail].emplace_back(first);
            }
        }

        vector<vector<string>> mergedAccounts;

        for (auto &it : accounts)
        {
            string owner = it[0];
            string first = it[1];

            if (vis.find(first) == vis.end())
            {
                vector<string> user;
                user.emplace_back(owner);

                DFS (first, user);

                sort(user.begin() + 1, user.end());
                mergedAccounts.emplace_back(user);
            }
        }

        return mergedAccounts;
    }
};