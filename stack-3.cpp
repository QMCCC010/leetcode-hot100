#include <stack>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string result;
        stack<int> mult;
        stack<char> st;

        for (char c : s) {
            if (isdigit(c)) mult.push((int)c);
            else if (c == '[' || isalpha(c)) st.push(c);
            else {
                string temp;
                while (st.top() != '[') {
                    temp += st.top();
                    st.pop();
                }
                st.pop();
                int iters = mult.top();
                mult.pop();
                int len = temp.size();
                for (int i = len - 1; i >= 0; i--) {
                    for (char c : temp) st.push(c);
                }
            }
        }
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};