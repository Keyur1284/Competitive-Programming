#include <bits/stdc++.h>
using namespace std;

How to generate random testcases
srand(time(NULL));
1 <= t <= 10
1 <= n <= 10000
1 <= a[i] <= 100000

int t = rand() % 10 + 1
cout << t << endl;

while(t--)
{
    int n = rand() % 10000 + 1
    cout << n << endl;

    for (int i = 0; i<n; i++)
    {
        cout << (rand() % 100000 + 1) << " ";
    }
}


How to check programs having single valued output
int cnt = 1;

while(cnt <= 1000)
{
    int n = rand() % 5 + 1;
    int a[n];

    for (int i = 0; i<n; i++)
        a[i] = rand() % 7 + 1;

    int correctAns = correctSolution(a,n);
    int myAns = mySolution(a,n);

    if (correctAns != myAns)
    {
        cout << n << endl;

        for (int i = 0; i<n; i++)
            cout << a[i] << " ";

        cout << endl;
        break;
    }

    cnt++;
}


How to do if there are multiple lines of output
Solution : Make struct

struct Node
{
    string ans;
    int a, b, c;
};

Node mySolution ()
{
    string s;
    int x, y, z;

    logic

    struct *Node;
    Node.a = x;
    Node.b = y;
    Node.c = z;

    return Node;
}

Node correctAns = correctSolution();
Node myAns = mySolution();

Then compare both of them



If time limit = 1s
no. of operations = 1e8


If time limit = 2s
no. of operations = 2 * 1e8
