#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// 单调栈
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 1 || height.size() == 2) return 0;
        int len = height.size();
        int water = 0;
        stack<int> monoStack;

        for (int i = 0; i < len; i++) {
            while (!monoStack.empty() && height[i] > height[monoStack.top()]) {
                // 当前的底
                int bottom = monoStack.top();
                monoStack.pop();

                // 如果此时栈为空，则本轮计算结束
                if (monoStack.empty()) break;

                // 凹槽右边界为当前节点
                int right = i;

                // 向左寻找左边界（由于上面的pop操作，一直取top就能找到左边界）
                int left = monoStack.top();

                // 计算水的体积，如果没有找到左边界，则算出来体积为0，加上0不影响最终答案
                int h = min(height[left], height[right]) - height[bottom];
                int w = right - left - 1;
                water += h * w;
            }
            monoStack.push(i);
        }
        return water;
    }
};


// 动态双指针，空间复杂度O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0;
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;


        while (left <= right) {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);

            if (leftMax <= rightMax) {
                water += leftMax - height[left];
                left++;
            }
            else {
                water += rightMax - height[right];
                right--;
            }
        }
        return water;
    }
};