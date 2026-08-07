#include <vector>
#include <unordered_map>
using namespace std;


// 哈希表，时间复杂度O(n), 空间复杂度O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // 记录每个数字出现的次数
        unordered_map<int, int> counts;
        int len = nums.size();

        for (int i = 0; i < len; i++) {
            if (!counts.count(nums[i])) counts[nums[i]] = 1;
            else counts[nums[i]]++;

            if (counts[nums[i]] > len / 2) return nums[i];
        }
        return -1;
    }
};


// 用栈实现众数和其他数字的消消乐
#include <stack>
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        stack<int> sameStack;

        for (int num : nums) {
            if (sameStack.empty() || num == sameStack.top()) sameStack.push(num);
            else sameStack.pop();
        }
        if (!sameStack.empty()) return sameStack.top();
        else return -1;
    }
};


// 摩尔投票法
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // 记录候选众数
        int candidate = nums[0];
        // 记录候选众数的票数
        int votes = 1;

        int len = nums.size();

        for (int i = 1; i < len; i++) {
            // 切换候选众数
            if (votes == 0) {
                candidate = nums[i];
                votes = 1;
            }
            else {
                // 当前数为候选众数，票数 +1
                if (nums[i] == candidate) votes++;

                // 否则票数 -1
                else votes--;
            }
        }
        return candidate;
    }
};