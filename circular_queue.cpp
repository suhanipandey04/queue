#include<iostream>
using namespace std;

class circularqueue {
    int* arr;
    int currsize, cap;
    int f, r;

public:
    circularqueue(int size) {
        cap = size;
        arr = new int[cap];
        currsize = 0;
        f = 0;
        r = -1;
    }

    void push(int data) {
        if (currsize == cap) {
            cout << "circular queue is full" << endl;
            return;   // prevent overflow
        }
        r = (r + 1) % cap;
        arr[r] = data;
        currsize++;
    }

    void pop() {
        if (currsize == 0) {
            cout << "circular queue is empty" << endl;
            return;   // prevent underflow
        }
        f = (f + 1) % cap;
        currsize--;
    }

    int front() {
        if (empty()) {
            cout << "circular queue is empty" << endl;
            return -1;
        }
        return arr[f];
    }

    bool empty() {
        return currsize == 0;
    }
};

int main() {
    circularqueue cq(3);

    cq.push(1);
    cq.push(2);
    cq.push(3);

    cout << "Front element: " << cq.front() << endl;

    cq.pop();
    cout << "Front after one pop: " << cq.front() << endl;

    cq.push(4);  // should wrap around
    cout << "Front after pushing 4: " << cq.front() << endl;

    cq.pop();
    cq.pop();
    cout << "Front after two more pops: " << cq.front() << endl;

    cq.pop(); // empty now
    cout << "Is queue empty? " << (cq.empty() ? "Yes" : "No") << endl;

    return 0;
}