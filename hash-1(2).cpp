#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numIndex;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            int temp = target - nums[i];
            if (numIndex.count(temp)) {
                result.push_back(numIndex[temp]);
                result.push_back(i);
                return result;
            }
            numIndex[nums[i]] = i;
        }
        return result;
    }
};