#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        // 记录最新的完全平方数
        vector<int> perfect_square;
        perfect_square.push_back(1);

        // 记录和为k的完全平方数的最少数量
        vector<int> dp(n + 1, 0);

        int root = 0;
        for (int i = 1; i <= n; i++) {
            root = (int) sqrt(i);
            if (root * root == i) {
                dp[i] = 1;
                perfect_square.push_back(i);
            }
            else {
                int min_counts = i;
                for (int num : perfect_square) min_counts = min(min_counts, dp[i - num] + 1);
                dp[i] = min_counts;
            }
            cout << dp[i] << " ";
        }
        return dp[n];
    }
};

int main() {
    Solution solution;
    int n = 12;
    int result = solution.numSquares(n);

}