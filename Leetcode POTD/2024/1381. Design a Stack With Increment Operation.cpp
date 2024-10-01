// Problem Link :- https://leetcode.com/problems/design-a-stack-with-increment-operation/

// Solved using vector
// Time Complexity :- O(1) for push, pop; O(k) for increment
// Space Complexity :- O(n)

class CustomStack {
private:

    vector<int> stackVector;
    int topIndex, maxSize;

public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        stackVector.resize(maxSize);
        topIndex = -1;
    }

    void push(int x) {
        
        if (topIndex < maxSize - 1)
            stackVector[++topIndex] = x;
    }

    int pop() {
    
        if (topIndex < 0)
            return -1;
        
        return stackVector[topIndex--];
    }

    void increment(int k, int val) {
        
        int limit = min(k, topIndex + 1);
        
        for (int i = 0; i < limit; i++)
            stackVector[i] += val;
    }
};



// Solved using vector with lazy increment
// Time Complexity :- O(1) for all operations
// Space Complexity :- O(n)

class CustomStack {
private:

    vector<int> stackArray, incrementArray;
    int topIndex, maxSize;

public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        stackArray.resize(maxSize);
        incrementArray.resize(maxSize);
        topIndex = -1;
    }

    void push(int x) {
        
        if (topIndex < maxSize - 1)
            stackArray[++topIndex] = x;
    }

    int pop() {
        
        if (topIndex < 0)
            return -1;

        int result = stackArray[topIndex] + incrementArray[topIndex];

        if (topIndex > 0)
            incrementArray[topIndex - 1] += incrementArray[topIndex];

        incrementArray[topIndex--] = 0;
        return result;
    }

    void increment(int k, int val) {
        
        if (topIndex >= 0) 
        {
            int incrementIndex = min(topIndex, k - 1);
            incrementArray[incrementIndex] += val;
        }
    }
};