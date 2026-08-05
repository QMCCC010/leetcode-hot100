#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        int maxNum = len + 1;

        // 把值为 i 的数字移动到 i - 1的位置上
        for (int i  = 0; i < len; i++) {
            if (nums[i] <= 0) nums[i] = maxNum + 1;

            while (nums[i] >= 1 && nums[i] < maxNum && nums[i] != i + 1) {
                if (nums[i] != nums[nums[i] - 1]) swap(nums[i], nums[nums[i] - 1]);
                else {
                    nums[i] = maxNum + 1;
                    break;
                }
            }
        }

        for (int i = 0; i < len; i++) {
            if (nums[i] != i + 1) return i + 1;
        }
        return maxNum;
    }
};