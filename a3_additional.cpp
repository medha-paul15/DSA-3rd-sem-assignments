#include <iostream>
#include <string>
using namespace std;

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
    //Q5
    checkIfSortableUsingStack();
    return 0;
}
