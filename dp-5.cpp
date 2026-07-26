#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, numeric_limits<int>::max());
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i - coin >= 0 && dp[i - coin] != numeric_limits<int>::max()) dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        if (dp[amount] == numeric_limits<int>::max()) return -1;
        else return dp[amount];
    }
};