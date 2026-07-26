#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;

        vector<vector<int>> dp(numRows, vector<int>(numRows, 0));
        result.push_back(vector<int>(1, 1));
        for (int i = 1; i < numRows; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                if (j == 0) dp[i][j] = 1;
                else if (j == i) dp[i][j] = 1;
                else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                temp.push_back(dp[i][j]);
            }
            result.push_back(temp);
        }
        return result;
    }
};