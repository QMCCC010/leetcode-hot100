#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        //记录s的前k个字符的子串是否为true
        vector<bool> dp(len + 1, false);
        dp[0] = true;
        string subStr = "";

        for (int i = 1; i <= len; i++) {
            subStr += s[i - 1];

            for (string str : wordDict) {
                int str_len = str.size();
                int j = i - str_len;
                if (j >= 0) {
                    string temp_str = s.substr(j, str_len);
                    if (temp_str == str && dp[j] == true) dp[i] = true;
                }
            }
        }
        return dp[len];
    }
};