#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        
        // 表示打劫前k家的最大金额
        vector<int> dp;
        dp.push_back(nums[0]);

        int len = nums.size();
        if (len > 1) {
            dp.push_back(max(nums[0], nums[1]));

            for (int i = 2; i < len; i++) dp.push_back(max (nums[i] + dp[i - 2], dp[i - 1]));
        }
        return dp[len - 1];
    }
};