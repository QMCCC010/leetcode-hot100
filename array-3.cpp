#include <vector>
using namespace std;

// 另开数组暴力求解
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> new_nums(len, 0);

        k = k % len;

        for (int i = len - k; i < len; i++) {
            new_nums[i - len + k] = nums[i];
        }
        for (int i = k; i < len; i++) {
            new_nums[i] = nums[i - k];
        }

        for (int i = 0; i < len; i++) nums[i] = new_nums[i];
    }
};


// 三步反转

void reverse(vector<int>& nums, int start, int end) {
    int temp = 0;
    while (start < end) {
        temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k = k % len;

        reverse(nums, 0, len - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, len - 1);
    }
};