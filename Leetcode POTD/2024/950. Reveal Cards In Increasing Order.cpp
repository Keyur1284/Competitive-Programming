// Problem Link :- https://leetcode.com/problems/reveal-cards-in-increasing-order/

// Solved using deque and sorting the input array
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n + logn)

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        
        int n = deck.size();
        sort(deck.begin(), deck.end());
        
        deque<int> dq;
        dq.emplace_back(deck[n - 1]);
        
        for (int i = n - 2; i >= 0; i--)
        {
            dq.emplace_front(dq.back());
            dq.pop_back();
            dq.emplace_front(deck[i]);
        }
        
        vector<int> cards(dq.begin(), dq.end());
        return cards;
    }
};



// Solved using queue and sorting the input array
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        
        int n = deck.size();
        sort(deck.begin(), deck.end());
        
        queue<int> q;
        for (int i = n - 1; i >= 0; i--)
        {
            if (!q.empty())
            {
                q.emplace(q.front());
                q.pop();
            }
            q.emplace(deck[i]);
        }
        
        vector<int> cards;
        while (!q.empty())
        {
            cards.emplace_back(q.front());
            q.pop();
        }
        
        reverse(cards.begin(), cards.end());
        return cards;
    }
};



class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        
        int n = deck.size();
        sort(deck.begin(), deck.end());

        vector<int> cards(n);
        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            q.emplace(i);
        }

        for (int i = 0; i < n; i++)
        {
            cards[q.front()] = deck[i];
            q.pop();
            
            if (!q.empty())
            {
                q.emplace(q.front());
                q.pop();
            }
        }

        return cards;
    }
};



// Solved using two pointers
// Time Complexity :- O(nlogn)
// Space Complexity :- O(1)

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        
        int n = deck.size();
        sort(deck.begin(), deck.end());

        vector<int> cards(n, -1);
        int cardInd = 0, deckInd = 0, skip = 0;

        while (deckInd < n)
        {
            if (cards[cardInd] == -1)
            {
                if (skip == 0)
                {
                    cards[cardInd] = deck[deckInd];
                    deckInd++;
                }

                skip ^= 1;
            }

            cardInd = (cardInd + 1) % n;
        }

        return cards;
    }
};