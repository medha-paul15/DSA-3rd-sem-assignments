#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) return; // stack overflow
    stack[++top] = c;
}

char pop() {
    if (top == -1) return '\0'; // stack empty
    return stack[top--];
}

char peek() {
    if (top == -1) return '\0';
    return stack[top];
}

bool isEmpty() {
    return top == -1;
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3; // right associative
    return 0;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, k = 0;
    top = -1;  // reset stack

    while (infix[i] != '\0') {
        char c = infix[i];

        // If operand, add to final
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            postfix[k++] = c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[k++] = pop();
            }
            if (!isEmpty() && peek() == '(')
                pop(); // remove '('
        }
        else if (isOperator(c)) {
            while (!isEmpty() && precedence(peek()) >= precedence(c)) {
                if (c == '^' && peek() == '^') // right associative check
                    break;
                postfix[k++] = pop();
            }
            push(c);
        }
        i++;
    }

    while (!isEmpty()) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0'; // null terminate
}

int main() {
    char infix[100];
    char postfix[100];

    cout << "Enter infix expression: ";
    cin.getline(infix, 100);

    infixToPostfix(infix, postfix);

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}