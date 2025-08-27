#include <iostream>
#include <string>
using namespace std;

void nearestSmallerElements() {

    int arr[] = {4, 5, 2, 10, 8};
    //int arr[] ={3,2,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result[n];
    
    int stack[n];   // array to use as stack
    int top = -1;   // stack is empty when top == -1

    for (int i = 0; i < n; i++) {
        // Pop elements from stack while top element >= arr[i]
        while (top >= 0 && stack[top] >= arr[i]) {
            top--;
        }

        if (top == -1) {
            // No smaller element to the left
            result[i] = -1;
        } else {
            // stack[top] is nearest smaller element
            result[i] = stack[top];
        }

        // Push current element onto stack
        stack[++top] = arr[i]; //stack mey, new elems from arr are pushed only after ensuring the previous ones are smaller than the new one
    }
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}



void nextGreaterElement() {
    int arr[] = {1,3,2,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result[50];

    int stack[50];  // Stack to store indices
    int top = -1;

    // Traverse array from right to left
    for (int i = n - 1; i >= 0; i--) {
        // Pop all elements smaller or equal to arr[i]
        while (top != -1 && arr[stack[top]] <= arr[i]) {
            top--;
        }

        // If stack is empty, no greater element to the right
        if (top == -1) {
            result[i] = -1;
        } else {
            result[i] = arr[stack[top]];
        }

        // Push current index to stack
        stack[++top] = i;
    }
    cout << "Next Greater Elements:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " -> " << result[i] << endl;
    }
}

void dailyTemperatures() {
    int temperatures[] = {73, 74, 75, 71, 69, 72, 76, 73};
    int n = sizeof(temperatures) / sizeof(temperatures[0]);
    int answer[50]; //max val

    int stack[50]; //max 
    int top = -1;

    for (int i = 0; i < n; i++) {
        while (top != -1 && temperatures[i] > temperatures[stack[top]]) {
            int idx = stack[top--]; //index of next warmer temp
            answer[idx] = i - idx; //difference: number of days to wait
        }
        stack[++top] = i;
    }

    while (top != -1) {
        answer[stack[top--]] = 0; //if no warmer day ahead
    }

    cout << "Days to wait for warmer temperature:\n";
    for (int i = 0; i < n; i++) {
        cout << answer[i] << " ";
    }
    cout << endl;
}

void checkIfSortableUsingStack() {
    // Input array A (you can change this for testing)
    int A[] = {4, 1, 2, 3};
    int n = sizeof(A) / sizeof(A[0]);

    // Stack S
    int S[50];//MAX 
    int top = -1;

    int expected = 1;  // We expect sorted output starting from 1
    int i = 0;

    while (i < n) {
        // Push current element of A into stack
        S[++top] = A[i++];
        
        // Pop from stack to B while the top equals expected
        while (top != -1 && S[top] == expected) {
            top--;
            expected++;
        }
    }

    // Final cleanup: pop remaining elements if they match expected
    while (top != -1 && S[top] == expected) {
        top--;
        expected++;
    }

    // If we have expected all n elements in order, it's possible
    if (expected == n + 1) {
        cout << "YES, it is possible to sort array B using stack S." << endl;
    } else {
        cout << "NO, it is NOT possible to sort array B using stack S." << endl;
    }
}

int main(){
    //Q1
    nearestSmallerElements();
    //Q3
    nextGreaterElement();
    //Q4
    dailyTemperatures();
    //Q5
    checkIfSortableUsingStack();
    return 0;
}