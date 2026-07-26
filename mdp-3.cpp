#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        // 表示从 i 到 j 的子串是否为回文串
        vector<vector<bool>> dp(len, vector<bool>(len, false));

        // 记录最长回文串
        string result = "";
        // 从短到长遍历长度
        for (int curr_len = 1; curr_len <= len; curr_len++) {
            // 遍历起点
            for (int i = 0; curr_len + i - 1 < len; i++) {
                int j = curr_len + i - 1;
                if (curr_len == 1) dp[i][j] = true;
                else if (curr_len == 2 && s[i] == s[j]) dp[i][j] = true;
                else {
                    if (s[i] == s[j] && dp[i + 1][j - 1]) dp[i][j] = true;
                }
                if (dp[i][j] && curr_len > result.size()) {
                    result = s.substr(i, curr_len);
                }
            }
        }
        return result;
    }
};