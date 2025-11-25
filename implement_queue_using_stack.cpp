#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;

    MyQueue() {
    }
    
    void push(int x) {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int ans = s1.top();
        s1.pop();
        return ans;
    }
    
    int top() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

int main() {
    MyQueue qu;

    // Push elements
    qu.push(10);
    qu.push(20);
    qu.push(30);

    cout << "Top element: " << qu.top() << endl;   // Should print 30
    cout << "Pop element: " << qu.pop() << endl;   // Should remove 30
    cout << "Top after pop: " << qu.top() << endl; // Should print 20

    qu.push(40);
    cout << "Top after pushing 40: " << qu.top() << endl; // Should print 40

    // Empty check
    while(!qu.empty()) {
        cout << "Popping: " << qu.pop() << endl;
    }

    cout << "Is stack empty? " << (qu.empty() ? "Yes" : "No") << endl;

    return 0;
}