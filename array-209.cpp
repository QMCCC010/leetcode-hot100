#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = nums.size() + 1;
        int sum = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            while (sum >= target) {
                int len = right - left + 1;
                minLen = min (minLen, len);
                sum -= nums[left];
                left++;
            }
        }
        if (minLen == nums.size() + 1) return 0;
        else return minLen;
    }
};