#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();

        //滚动记录以第k个数结尾的最大乘积
        int curr_max = nums[0];
        //滚动记录以第k个数结尾的最小乘积
        int curr_min = nums[0];

        for (int num : nums) {
            curr_max = max ({curr_max * num, curr_min * num, num});
            curr_min = min ({curr_max * num, curr_min * num, num});
        }
        return curr_max;
    }
};