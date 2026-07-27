#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> result;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> group;
        backTracking(nums, 0, group);
        return result;
    }

    void backTracking(vector<int>& nums, int startIndex, vector<int>& group) {
        result.push_back(group);

        for (int i = startIndex; i < nums.size(); i++) {
            group.push_back(nums[i]);
            backTracking(nums, i + 1, group);
            group.pop_back();
        }
    }
};