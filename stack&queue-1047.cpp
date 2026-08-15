#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> valid_stack;
        int ptr = s.size() - 1;

        for (char c : s) {
            if (valid_stack.empty() || valid_stack.top() != c)
                valid_stack.push(c);
            else {
                valid_stack.pop();
                ptr -= 2;
            }
        }
        int new_len = ptr + 1;
        while (ptr >= 0) {
            s[ptr] = valid_stack.top();
            valid_stack.pop();
            ptr--;
        }
        s.resize(new_len);
        return s;
    }
};


// 字符串有push,pop接口,可当成栈处理
class Solution {
public:
    string removeDuplicates(string s) {
        string result;

        for (char c : s) {
            if (result.empty() || result.back() != c) result += c;
            else result.pop_back();
        }
        return result;
    }
};