#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        if (len == 0 || len == 1) return true;
        int farest = 0;

        for (int i = 0; i < len && i <= farest; i++) {
            farest = max(farest, i + nums[i]);
            if (farest >= len - 1) return true;
        }
        return false;
    }
};