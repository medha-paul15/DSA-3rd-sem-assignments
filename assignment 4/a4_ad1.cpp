#include <iostream>
#include <string>
#include <queue>
using namespace std;


void dectobinary(int n)
{
    queue<string> q;

    q.push("1");

    while (n--) {
        
        // print the front of queue
        string s1 = q.front();
        q.pop();
        cout << s1 << "\n";

        string s2 = s1; 

        
        q.push(s1.append("0"));
        q.push(s2.append("1"));
    }
}

int main()
{
    int n = 5;

    dectobinary(n);
    return 0;
}