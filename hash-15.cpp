#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


// 哈希表法
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            // 跳过第一个重复数字
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int target = -nums[i];
            unordered_map<int, int> existNum;
            for (int j = i + 1; j < n; j++) {
                if (existNum.count(target - nums[j])) {
                    vector<int> path;
                    path.push_back(nums[i]);
                    path.push_back(nums[j]);
                    path.push_back(target-nums[j]);
                    result.push_back(path);

                    // 跳过第二个数字
                    while (j + 1 < n && nums[j + 1] == nums[j]) j++; 
                }
                else
                    existNum[nums[j]] = j;
            }
        }
        return result;
    }
};


// 双指针法
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();

        if (n < 3) return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            // 第一个数字去重
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // 剪枝一：最小值大于0，无解
            if (nums[i] + nums[i + 1] + nums[i + 2] > 0) break;

            // 剪枝二：最大值小于0，当前数字nums[i]无解，找下一个
            if (nums[i] + nums[n - 1] + nums[n - 2] < 0) continue;

            int target = -nums[i];
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[left] + nums[right];

                // 找到一组解
                if (sum == target) {
                    result.push_back({nums[i], nums[left], nums[right]});

                    // 去重left
                    while (left < right && nums[left] == nums[left + 1])left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                }
                else if (sum < target) left++;
                else right --;
            }
        }
        return result;
    }
};