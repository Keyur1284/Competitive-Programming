//Problem Link :- https://www.lintcode.com/problem/892/

//This code is accepted on Leetcode but on Lintcode, there are some issues.
class Solution {
public:
    /**
     * @param words: a list of words
     * @return: a string which is correct order
     */

    int convert (char c)
    {
        return (c - 'a');
    }

    bool checkCycle (int node, vector <int> adj[], vector <int> &vis, vector <int> &dfsVis, stack <int> &st)
    {
        vis[node] = 1;
        dfsVis[node] = 1;
        
        for (auto it : adj[node])
        {
            if(!vis[it])
                if (checkCycle(it, adj, vis, dfsVis, st) == true)
                    return true;

            else if (dfsVis[it] == 1)
                return true;
        }

        dfsVis[node] = 0;
        st.emplace(node);
        return false;
    }

    string alienOrder(vector<string> &words) {
        
        int n = words.size();
        vector <int> adj [26], present(26, 0), vis(26, 0), dfsVis(26, 0);

        for (int i = 0; i<n; i++)
        {
            for (auto it : words[i])
                present[convert(it)] = 1;
        }

        for (int i = 0; i<n - 1; i++)
        {
            string word1 = words[i];
            string word2 = words[i+1];

            int temp = word1.size();

            for (int j = 0; j < temp; j++)
            {
                if (j >= word2.size())
                    return "";

                if (word1[j] != word2[j])
                {
                    adj[convert(word1[j])].emplace_back(convert(word2[j]));
                    break;
                }
            }
        }

        stack <int> st;

        for (int i = 0; i<26; i++)
        {
            if (!vis[i] && present[i] == 1)
                if(checkCycle(i, adj, vis, dfsVis, st) == true)
                    return "";
        }

        string ans = "";

        while (!st.empty())
        {
            ans += char (st.top() + 'a');
            st.pop();
        }

        return ans;
    }
};