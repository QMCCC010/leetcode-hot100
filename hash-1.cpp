#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 哈希表单次遍历
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> valIndex;
        int len = nums.size();

        for (int i = 0; i < len; i++) {
            if (valIndex.count(target - nums[i])) {
                result.push_back(i);
                result.push_back(valIndex[target - nums[i]]);
                return result;
            }
            else valIndex[nums[i]] = i;
        }
        return result;
    }
};