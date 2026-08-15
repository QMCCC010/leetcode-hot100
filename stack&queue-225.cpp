#include <queue>
using namespace std;

class MyStack {
    queue<int> queue1;
    int topElement;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        topElement = x;
        queue1.push(x);
    }
    
    int pop() {
        int counts = queue1.size() - 1;
        while (counts > 0) {
            int top = queue1.front();
            if (counts == 1) topElement = top;
            queue1.pop();
            queue1.push(top);
            counts--;
        }
        int top = queue1.front();
        queue1.pop();
        return top;
    }
    
    int top() {
        return topElement;
    }
    
    bool empty() {
        return queue1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */