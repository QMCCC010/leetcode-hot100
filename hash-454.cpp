#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int result = 0;
        int n = nums1.size();
        // 分组分别存num1 + num2, num3 + num4
        unordered_map<int, int> sumCount1;
        unordered_map<int, int> sumCount2;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int sum1 = nums1[i] + nums2[j];
                int sum2 = nums3[i] + nums4[j];
                sumCount1[sum1]++;
                sumCount2[sum2]++;
            }
        }

        for (const auto& myPair : sumCount1) {
            int target = -myPair.first;
            if (sumCount2.count(target))
                result += myPair.second * sumCount2[target];
        }
        return result;
    }
};