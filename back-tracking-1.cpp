#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(result, 0, nums);

        return result;
    }

    void backtrack(vector<vector<int>>& result, int start, vector<int>& nums) {
        if (start >= nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            swap(nums[i], nums[start]);
            backtrack(result, start + 1, nums);
            swap(nums[i], nums[start]);
        }
    }
};