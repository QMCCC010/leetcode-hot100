#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        int left = 0, right = nums.size() - 1;

        int index = right;
        while (left <= right) {
            int leftNum = nums[left] * nums[left];
            int rightNum = nums[right] * nums[right];

            if (leftNum >= rightNum) {
                result[index--] = leftNum;
                left++;
            }
            else {
                result[index--] = rightNum;
                right--;
            }
        }
        return result;
    }
};