#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        // dp[i][j]表示将 word1 的前 i 个字符 替换呈 word2 的前 j 个字符的zui最少操作数
        int len1 = word1.size(), len2 = word2.size();
        vector<vector<int>> dp(len1, vector<int>(len2, len1 + len2));
        
    }
};