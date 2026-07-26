#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result = 0;
        int len = nums.size();
        int prefix = 0;
        unordered_map<int, int> prefixsum_count; // 记录前缀和出现的次数
        prefixsum_count[0] = 1;

        for (int i = 0; i < len; i++) {
            prefix += nums[i];

            if (prefixsum_count.find(prefix - k) != prefixsum_count.end()) 
                result += prefixsum_count[prefix - k];
            
            prefixsum_count[prefix]++;
        }
        return result;
    }
};