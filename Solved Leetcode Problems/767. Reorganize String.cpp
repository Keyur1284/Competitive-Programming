// Problem Link :- https://leetcode.com/problems/reorganize-string/

// Solved by counting frequency and priority_queue
// Time Complexity :- O(n * log(k))     k <= 26
// Space Complexity :- O(k)

class Solution {
public:
    string reorganizeString(string s) {
        
        vector<int> freq(26, 0);

        for (auto &it : s)
            freq[it - 'a']++;

        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < 26; i++)
        {
            if (freq[i])
            {
                pq.emplace(freq[i], i);
            }
        }

        string ans = "";

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int count = it.first, index = it.second;
            char k = index + 'a';

            if (ans.empty() || ans.back() != k)
            {
                ans += k;
                
                if (count > 1)
                    pq.emplace(count - 1, index);
            }

            else
            {
                if (pq.empty())
                    return "";

                auto it2 = pq.top();
                pq.pop();

                int count2 = it2.first, index2 = it2.second;
                char k2 = index2 + 'a';

                ans += k2;

                if (count2 > 1)
                    pq.emplace(count2 - 1, index2);

                pq.emplace(it);
            }
        }

        return ans;
    }
};



// Solved by counting frequency and filling alternate positions
// Time Complexity :- O(n)
// Space Complexity :- O(k)

class Solution {
public:
    string reorganizeString(string s) {
        
        vector<int> freq(26, 0);

        for (auto &it : s)
            freq[it - 'a']++;

        int maxi = 0, maxInd = -1;

        for (int i = 0; i < 26; i++)
        {
            if (freq[i] > maxi)
            {
                maxi = freq[i];
                maxInd = i;
            }
        }

        int len = s.length();

        if (maxi > (len + 1)/2)
            return "";

        string ans = s;
        int index = 0;

        while (freq[maxInd] > 0)
        {
            ans[index] = maxInd + 'a';
            index += 2;
            freq[maxInd]--;
        }

        for (int i = 0; i < 26; i++)
        {
            while(freq[i] > 0)
            {
                if (index >= len)
                    index = 1;

                ans[index] = i + 'a';
                index += 2;
                freq[i]--;
            }
        }

        return ans;
    }
};