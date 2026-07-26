#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// 暴力解法
// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int> result;
//         int len = nums.size();

//         for (int left = 0, right = k - 1;  right < len; left++, right++) {
//             int max_num = nums[left];
//             for (int i = left; i <= right; i++) {
//                 max_num = max(max_num, nums[i]);
//             }
//             result.push_back(max_num);
//         }
//         return result;
//     }
// };

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        priority_queue<pair<int, int>> pq;
        int len = nums.size();
        for (int i = 0; i < k; i++) pq.push({nums[i], i});
        result.push_back(pq.top().first);

        for (int i = k; i < len; i++) {
            pq.push({nums[i], i});

            while (pq.top().second < i - k + 1) pq.pop();

            result.push_back(pq.top().first);
        }

        return result;
    }
};