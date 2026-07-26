#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size();
        int len2 = text2.size();

        // dp[i][j]表示 text1 前 i 个字符的子串和 text2 前 j 个字符的子串的最长公共子序列
        vector<vector<int>> dp(len1, vector<int>(len2, 0));

        for (int j = 0; j < len2; j++) {
            if (text2[j] == text1[0]) {
                for (int k = j; k < len2; k++) dp[0][k] = 1;
                break;
            }
        }
        for (int i = 0; i < len1; i++) {
            if (text1[i] == text2[0]) {
                for (int k = i; k < len1; k++) dp[k][0] = 1;
                break;
            }
        }

        for (int i = 1; i < len1; i++) {
            for (int j = 1; j < len2; j++) {
                if(text2[j] == text1[i]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[len1 - 1][len2 - 1];
    }
};