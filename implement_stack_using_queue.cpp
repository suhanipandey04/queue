#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {
    }
    
    void push(int x) {
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {
        int ans = q1.front();
        q1.pop();
        return ans;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack st;

    // Push elements
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl;   // Should print 30
    cout << "Pop element: " << st.pop() << endl;   // Should remove 30
    cout << "Top after pop: " << st.top() << endl; // Should print 20

    st.push(40);
    cout << "Top after pushing 40: " << st.top() << endl; // Should print 40

    // Empty check
    while(!st.empty()) {
        cout << "Popping: " << st.pop() << endl;
    }

    cout << "Is stack empty? " << (st.empty() ? "Yes" : "No") << endl;

    return 0;
}