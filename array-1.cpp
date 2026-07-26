#include <vector>
#include <algorithm>
using namespace std;


// 前缀和法（用前缀和表示任意一个子串的和）
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_num = nums[0];
        int prefixsum = 0;
        int min_prefixsum = 0;
        int len = nums.size();

        for (int num : nums) {
            prefixsum += num;
            max_num = max(max_num, prefixsum - min_prefixsum);
            min_prefixsum = min(min_prefixsum, prefixsum);
        }

        return max_num;
    }
};