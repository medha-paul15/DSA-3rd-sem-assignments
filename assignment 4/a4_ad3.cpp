#include <iostream>
#include <stack>
#include <queue>
using namespace std;

bool checkSorted(int n, queue<int>& q) {
    stack<int> st;
    int expected = 1; // the number we are waiting for

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == expected) {
            // If the right number, take it directly
            expected++;
        } else {
            // If stack is not empty and top is smaller, order breaks
            if (!st.empty() && st.top() < current) {
                return false;
            }
            // Otherwise, put it in the stack
            st.push(current);
        }

        // After each step, check stack top
        while (!st.empty() && st.top() == expected) {
            st.pop();
            expected++;
        }
    }

    // At the end, if we placed all numbers correctly, return true
    return (expected - 1 == n && st.empty());
}

int main() {
    queue<int> q;
    q.push(5);
    q.push(1);
    q.push(3);
    q.push(2);
    q.push(4);

    int n = q.size();

    if (checkSorted(n, q))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}