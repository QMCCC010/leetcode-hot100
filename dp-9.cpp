#include <vector>
using namespace std;

// nums每个数字同时代表了其重量和价值，目的是判断容量为 sum/2 的背包最大是否能装价值 sum/2
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int len = nums.size();
        for (int num : nums) sum += num;
        if (sum % 2 != 0) return false;

        int target = sum / 2;

        // 容量为k的背包能装的最大值
        vector<int> dp(target + 1, 0);

        for (int i = 0; i < len; i++) {
            for (int j = target; j >= nums[i]; j--) {
                dp[j] = max (dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        if (dp[target] == target) return true;
        return false;
    }
};