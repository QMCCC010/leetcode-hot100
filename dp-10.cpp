#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        // 表示以第k个字符结尾的最长有效括号的长度
        int len = s.size();
        vector<int> dp(len, 0);
        if (len > 1 && s[0] == '(' && s[1] == ')') dp[1] = 2;

        for (int i = 2; i < len; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') dp[i] = dp[i - 2] + 2;
                else {
                    int m = i - dp[i - 1] - 1;
                    if (m >= 0 && s[m] == '(') dp[i] = m > 0 ? dp[i - 1] + dp[i - dp[i - 1] - 2] + 2 : dp[i - 1] + 2;
                }
            }
        }
        int result = 0;
        for (int sLen : dp) result = max (result, sLen);
        return result;
    }
};