#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] != 0) {
                swap(nums[slow], nums[fast]);
                slow++;
            }
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 0, 2, 0, 0, 8, 4, 5, 3, 7, 2, 1, 1, 1, 0, 1, 0};
    solution.moveZeroes(nums);
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}