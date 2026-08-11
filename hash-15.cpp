#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int target = -nums[i];
            unordered_map<int, int> existNum;
            for (int j = i + 1; j < n; j++) {
                if (existNum[target - nums[j]]) {
                    vector<int> path;
                    path.push_back(nums[i]);
                    path.push_back(nums[j]);
                    path.push_back(-nums[i]-nums[j]);
                    result.push_back(path);
                }
                existNum[nums[j]] = j;
            }
        }
        return result;
    }
};