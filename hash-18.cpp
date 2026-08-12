#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();

        if (n < 4) return result;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++) {
            // 去重第一个数字
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // 剪枝一
            long long sum = nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3];
            if (sum > target) break;

            // 剪枝二
            sum = nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3];
            if (sum < target) continue;

            for (int j = i + 1; j < n - 2; j++) {
                // 去重第二个数字
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                // 剪枝一
                sum = nums[i] + nums[j] + nums[j + 1] + nums[j + 2];
                if (sum > target) break;

                // 剪枝二
                sum = nums[i] + nums[j] + nums[n - 1] + nums[n - 2];
                if (sum < target) continue;

                int left = j + 1, right = n - 1;
                while (left < right) {
                    sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        while (left < right && nums[left + 1] == nums[left]) left++;
                        while (left < right && nums[right - 1] == nums[right]) right--;
                        left++;
                        right--;
                    }
                    else if (sum < target) left++;
                    else right--;
                }
            }
        }
        return result;
    }
};