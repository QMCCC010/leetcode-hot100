#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_map<int, int> hm1, hm2;

        for (int num : nums1) hm1[num]++;
        for (int num : nums2) hm2[num]++;

        for (const auto& myPair : hm1) {
            if (hm2.count(myPair.first)) {
                result.push_back(myPair.first);
            }
        }
        return result;
    }
};


// 哈希集合，一次遍历
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> numSet(nums1.begin(), nums1.end());
        vector<int> result;

        for (int num : nums2) {
            if (numSet.erase(num)) result.push_back(num);
        }
        return result;
    }
};