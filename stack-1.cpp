#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') myStack.push(c);
            else {
                if (!myStack.empty()) {
                    if (c == ')') {
                        if (myStack.top() == '(') myStack.pop();
                        else return false;
                    }
                    else if (c == ']') {
                        if (myStack.top() == '[') myStack.pop();
                        else return false;
                    }
                    else {
                        if (myStack.top() == '{') myStack.pop();
                        else return false;
                    }
                }
                else return false;
            }
        }
        if (myStack.empty()) return true;
        return false;
    }
};