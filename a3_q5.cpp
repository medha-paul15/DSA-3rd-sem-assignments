#include <iostream>
using namespace std;

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    char expr[MAX];
    cout << "Enter postfix expression: ";
    cin >> expr;

    int i = 0;
    while (expr[i] != '\0') {
        char c = expr[i];

        if (c >= '0' && c <= '9') {
            push(c - '0');
        } else {
            int b = pop();
            int a = pop();
            if (c == '+') push(a + b);
            else if (c == '-') push(a - b);
            else if (c == '*') push(a * b);
            else if (c == '/') push(a / b);
        }
        i++;
    }

    cout << "Result: " << pop() << endl;
    return 0;
}