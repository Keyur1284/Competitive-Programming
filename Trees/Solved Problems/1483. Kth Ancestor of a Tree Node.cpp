// Problem Link :- https://leetcode.com/problems/kth-ancestor-of-a-tree-node/

// Solved using Binary Lifting
// Time Complexity :- O(nlogn) for precomputation and O(logn) for each query
// Space Complexity :- O(nlogn)

class TreeAncestor {
public:

    int LOG;
    vector<vector<int>> dp;

    TreeAncestor(int n, vector<int>& parent) {
        
        LOG = 1 + ceil(1.0 * log2(n));

        // Alternate way to calculate LOG
        /*
            while ((1 << LOG) <= n)
                LOG++;
        */

        // dp[node][level] = 2^level th parent of node
        dp.assign(n, vector<int> (LOG, -1));

        for (int node = 0; node < n; node++)
            dp[node][0] = parent[node];

        for (int level = 1; level < LOG; level++)
        {
            for (int node = 0; node < n; node++)
            {
                int levelPar = dp[node][level - 1];

                if (levelPar != -1)
                    dp[node][level] = dp[levelPar][level - 1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        
        for (int level = 0; level < LOG; level++)
        {
            if (k & (1 << level))
                node = dp[node][level];

            if (node == -1)
                break;
        }

        // Alternate way to write the above loop
        /*
            for (int level = LOG - 1; level >= 0; level--)
            {
                if (k >= (1 << level))
                {
                    node = dp[node][level];
                    k -= (1 << level);
                }

                if (node == -1)
                    break;
            }
        */
        
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */