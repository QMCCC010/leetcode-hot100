#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        
        // 表示机器人走到（i, j）有多少种路径
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // 第一行只能往右走，只有一条路径
        for (int j = 0; j < n; j++) dp[0][j] = 1;
        // 第一列只能往下走，只有一条路径
        for (int i = 0; i < m; i++) dp[i][0] = 1;

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};