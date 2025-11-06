#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    void push(char x) {
        if (top == MAX - 1) return;
        arr[++top] = x;
    }

    char pop() {
        if (top == -1) return '\0';
        return arr[top--];
    }

    int isEmpty() {
        return top == -1;
    }

    char peek() {
        if (top == -1) return '\0';
        return arr[top];
    }
};

int main() {
    char exp[200];
    cout<<"type ur expression out: ";
    cin.getline(exp, 200);

    Stack s;
    int i = 0, f = 1; //initial cond f=1-> true i.e balanced
    //only push in operators inside the stack

    while (exp[i] != '\0') {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            s.push(exp[i]); //if opening brackets-> push directly
        } 
        else if (exp[i] == ')') {
            if (s.isEmpty() || s.pop() != '(') { //check if the last item on top was opening paran. if not then f=0;
                f = 0;
                break;
            }
        } 
        else if (exp[i] == '}') {
            if (s.isEmpty() || s.pop() != '{') {
                f = 0;
                break;
            }
        } 
        else if (exp[i] == ']') {
            if (s.isEmpty() || s.pop() != '[') {
                f = 0;
                break;
            }
        }
        i++;
    }

    if (!s.isEmpty()){
        f = 0; 
    } 
    cout << (f ? "balanced" : "not balanced") << "\n";

    return 0;
}    