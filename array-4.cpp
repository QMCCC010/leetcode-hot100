#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> result(len);
        vector<int> prefix_mult(len + 1);
        vector<int> postfix_mult(len + 1);
        prefix_mult[0] = 1;
        postfix_mult[len] = 1;

        // 前缀积和后缀积
        for (int i = 0; i < len; i++) prefix_mult[i + 1] = nums[i] * prefix_mult[i]; 
        for (int i = len - 1; i > 0; i--) postfix_mult[i] = nums[i] * postfix_mult[i + 1];

        for (int i = 0; i < len; i++) {
            result[i] = prefix_mult[i] * postfix_mult[i + 1];
        }
        return result;
    }
};

