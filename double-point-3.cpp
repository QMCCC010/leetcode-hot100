#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int x = 0; x < nums.size() - 2; x++) {
            int slow = x + 1;
            int fast = nums.size() - 1;
            while(slow < fast) {
                if (nums[slow] + nums[fast] < -nums[x]) slow++;
                else if (nums[slow] + nums[fast] > -nums[x]) fast--;
                else {
                    result.insert({nums[x], nums[slow], nums[fast]});
                    slow++;
                }
            }
        }
        return vector<vector<int>>(result.begin(), result.end());
    }
};

