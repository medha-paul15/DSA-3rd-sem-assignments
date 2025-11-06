#include <iostream>
#include <queue>
using namespace std;

void printQueue(queue<int> q);
// Function to find index of minimum in the first 'unsortedSize' elements
int findMinIndex(queue<int>& q, int unsortedSize) {
    int min_index = 0;
    int min_value = INT_MAX;
    int n = q.size();

    for (int i = 0; i < n; i++) {
        int curr = q.front();
        

        if (i < unsortedSize && curr <= min_value) {
            min_value = curr;
            min_index = i;
        }
        q.pop();
        q.push(curr);
    }

    return min_index;
}

// Move element at min_index to the rear
void moveMinToRear(queue<int>& q, int min_index) {
    int n = q.size();
    int min_value;

    for (int i = 0; i < n; i++) {
        int curr = q.front();
        q.pop();

        if (i == min_index) {
            min_value = curr; // skip it now
        } else {
            q.push(curr);
        }
    }
    cout<<"inside func: ";
    printQueue(q);
    q.push(min_value); // put the minimum at rear
}

// Sort queue without extra space
void sortQueue(queue<int>& q) {
    int n = q.size();
    int i=1;
    for (int unsortedSize = n; unsortedSize > 0; unsortedSize--) {
        int min_index = findMinIndex(q, unsortedSize);
        cout<<endl<<"min index in iter "<<i++<<":"<<min_index<< endl<<"and unsorted size:"<<unsortedSize<<endl;
        moveMinToRear(q, min_index);
        cout<<"queue now: ";
        printQueue(q);
    }
}

// Helper to print queue
void printQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    q.push(30);
    q.push(11);
    q.push(4);
    q.push(15);

    cout <<endl<< "Original queue: ";
    printQueue(q);

    sortQueue(q);

    cout << endl<<"Sorted queue: ";
    printQueue(q);

    return 0;
}
