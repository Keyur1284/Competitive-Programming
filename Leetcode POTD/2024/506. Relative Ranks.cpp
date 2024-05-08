// Problem Link :- https://leetcode.com/problems/relative-ranks/

// Solved by Sorting and using vector of pairs
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        int n = score.size();
        vector<pair<int, int>> players;

        for (int i = 0; i < n; i++)
            players.emplace_back(score[i], i);

        sort(players.rbegin(), players.rend());
        
        vector<string> answer(n);

        for (int i = 0; i < n; i++)
        {
            if (i == 0)
                answer[players[i].second] = "Gold Medal";

            else if (i == 1)
                answer[players[i].second] = "Silver Medal";

            else if (i == 2)
                answer[players[i].second] = "Bronze Medal";

            else
                answer[players[i].second] = to_string(i + 1);
        }

        return answer;
    }
};



// Solved by Sorting and using unordered_map
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        int n = score.size();
        unordered_map<int, int> scoreToIndex;

        for (int i = 0; i < n; i++)
        {
            scoreToIndex[score[i]] = i;
        }

        sort(score.rbegin(), score.rend());
        
        vector<string> answer(n);

        for (int i = 0; i < n; i++)
        {
            if (i == 0)
                answer[scoreToIndex[score[i]]] = "Gold Medal";

            else if (i == 1)
                answer[scoreToIndex[score[i]]] = "Silver Medal";

            else if (i == 2)
                answer[scoreToIndex[score[i]]] = "Bronze Medal";

            else
                answer[scoreToIndex[score[i]]] = to_string(i + 1);
        }

        return answer;
    }
};



// Solved using priority_queue
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        int n = score.size();
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < n; i++)
        {
            pq.emplace(score[i], i);
        }

        const vector<string> medals = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        vector<string> answer(n);

        for (int i = 0, rank = 1; i < n; i++, rank++)
        {
            auto [points, index] = pq.top();
            pq.pop();

            if (rank <= 3)
                answer[index] = medals[rank - 1];
            
            else
                answer[index] = to_string(rank);
        }

        return answer;
    }
};



// Solved using vector as map
// Time Complexity :- O(n + maxScore)
// Space Complexity :- O(n + maxScore)

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        int n = score.size();
        int maxScore = *max_element(score.begin(), score.end());
        vector<int> scoreToIndex(maxScore + 1, -1);

        for (int i = 0; i < n; i++)
        {
            scoreToIndex[score[i]] = i;
        }
        
        const vector<string> medals = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        vector<string> answer(n);

        for (int i = maxScore, rank = 1; i >= 0; i--)
        {
            if (scoreToIndex[i] != -1)
            {
                int index = scoreToIndex[i];

                if (rank <= 3)
                    answer[index] = medals[rank - 1];
                
                else
                    answer[index] = to_string(rank);

                rank++;
            }
        }

        return answer;
    }
};