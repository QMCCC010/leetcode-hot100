#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        if (nums.empty()) return vector<int>(2, -1);

        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (right - left) / 2 + left;
            if (nums[mid] == target) {
                result.push_back(findStart(nums, target, left, mid - 1));
                result.push_back(findEnd(nums, target, mid + 1, right));
                break;
            }
            else if (nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }

        if (!result.empty()) return result;
        else return vector<int>(2, -1);
    }

    int findStart(vector<int>& nums, int target, int left, int right) {
        while (left <= right) {
            int mid = (right - left) / 2 + left; //防止直接用right + left溢出
            if (nums[mid] == target) return findStart(nums, target, left, mid - 1);
            else if (nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return right + 1;
    }

    int findEnd(vector<int>& nums, int target, int left, int right) {
        while (left <= right) {
            int mid = (right - left) / 2 + left;
            if (nums[mid] == target) return findEnd(nums, target, mid + 1, right);
            else if (nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return left - 1;
    }
};