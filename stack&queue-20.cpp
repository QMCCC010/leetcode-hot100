#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // 快速剪枝：奇数长度不可能有效
        if (s.length() % 2 == 1) return false;

        stack<char> valid_stack;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') valid_stack.push(c);
            else if (c == ')') {
                if (valid_stack.empty() || valid_stack.top() != '(') return false;
                else valid_stack.pop();
            }
            else if (c == ']') {
                if (valid_stack.empty() || valid_stack.top() != '[') return false;
                else valid_stack.pop();
            }
            else {
                if (valid_stack.empty() || valid_stack.top() != '{') return false;
                else valid_stack.pop();
            }
        }
        if (valid_stack.empty()) return true;
        else return false;
    }
};