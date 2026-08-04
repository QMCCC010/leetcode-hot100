#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


// DP 预处理 + 回溯枚举，startIndex充当分割符
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int maxLen = s.size();

        // 动态规划预处理，找出所有回文串, dp[i][j] 表示从 i 到 j 的子串是否为回文串
        vector<vector<char>> dp(maxLen, vector<char>(maxLen, 0));

        for (int len = 1; len <= maxLen; len++) {
            for (int i = 0; i < maxLen - len + 1; i++) {
                int j = i + len - 1;
                if (len == 1) dp[i][j] = 1;
                else if (len == 2 && s[i] == s[j]) dp[i][j] = 1;
                else {
                    if (s[i] == s[j] && dp[i + 1][j - 1]) dp[i][j] = 1;
                }
            }
        }

        vector<string> path;
        vector<vector<string>> result;
        backTracking(s, dp, 0, path, result);
        return result;
    }

    void backTracking(const string& s, const vector<vector<char>>& dp, int startIndex, vector<string>& path, vector<vector<string>>& result) {
        if (startIndex >= s.size()) {
            result.push_back(path);
            return;
        }

        int maxLen = s.size();
        for (int i = startIndex; i < maxLen; i++) {
            if (dp[startIndex][i] == 1) {
                string temp = s.substr(startIndex, i - startIndex + 1);
                path.push_back(temp);
                backTracking(s, dp, i + 1, path, result);
                path.pop_back();
            }
        }
    }
};