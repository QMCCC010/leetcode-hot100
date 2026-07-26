#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        // 以第k个数字结尾的最长严格递增子序列长度
        vector<int> dp(len, 1);

        for (int i = 1; i < len; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        
        int result = 1;
        for (int i = 0; i < len; i++) {
            result = max (result, dp[i]);
        }
        return result;
    }
};