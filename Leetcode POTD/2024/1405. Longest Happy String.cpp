// Problem Link :- https://leetcode.com/problems/longest-happy-string/

// Solved using priority_queue
// Time Complexity :- O((a + b + c) * log(3))
// Space Complexity :- O(1)

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        
        priority_queue<pair<int, char>> pq;
        
        if (a > 0)
            pq.emplace(a, 'a');

        if (b > 0)
            pq.emplace(b, 'b');

        if (c > 0)
            pq.emplace(c, 'c');

        string ans = "";
        
        while (!pq.empty()) 
        {
            pair<int, char> p = pq.top();
            pq.pop();
            int count = p.first;
            char character = p.second;
            
            if (ans.length() >= 2 and ans[ans.length() - 1] == p.second && ans[ans.length() - 2] == p.second) 
            {
                if (pq.empty()) 
                    break;

                pair<int, char> temp = pq.top();
                pq.pop();
                ans += temp.second;
                
                if (temp.first - 1 > 0)
                    pq.emplace(temp.first - 1, temp.second);
            } 
            
            else 
            {
                count--;
                ans = ans + character;
            }

            if (count > 0)
                pq.emplace(count, character);
        }
        return ans;
    }
};



// Solved without using priority_queue
// Time Complexity :- O(a + b + c)
// Space Complexity :- O(1)

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        
        int curra = 0, currb = 0, currc = 0, totalIterations = a + b + c;
        string ans = "";

        for (int i = 0; i < totalIterations; i++) 
        {
            if ((a >= b && a >= c && curra != 2) || (a > 0 && (currb == 2 || currc == 2))) 
            {
                ans += 'a';
                a--;
                curra++;
                currb = 0;
                currc = 0;
            } 
            
            else if ((b >= a && b >= c && currb != 2) || (b > 0 && (currc == 2 || curra == 2))) 
            {
                ans += 'b';
                b--;
                currb++;
                curra = 0;
                currc = 0;
            } 
            
            else if ((c >= a && c >= b && currc != 2) || (c > 0 && (curra == 2 || currb == 2))) 
            {
                ans += 'c';
                c--;
                currc++;
                curra = 0;
                currb = 0;
            }
        }
        
        return ans;
    }
};