#include <vector>
using namespace std;


// 相向双指针
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int right = nums.size() - 1;
        for (int left = 0; left <= right; left++) {
            while (right >= 0 && nums[right] == val) right--;
            if (left >= right) break;
            if (nums[left] == val) swap(nums[left], nums[right]);
        }
        return right + 1;
    }
};


// 快慢指针
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // slow指向下一个能放有效元素的位置，同时slow的大小也正好等于有效元素的数量
        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++) {
            // 找到一个有效元素
            if (nums[fast] != val) {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
};