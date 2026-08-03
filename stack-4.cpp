#include <vector>
#include <stack>
using namespace std;

// 单调栈
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        stack<pair<int, int>> monoStack;
        vector<int> result(len, 0);

        for (int i = 0; i < len; i++) {
            while (!monoStack.empty() && temperatures[i] > monoStack.top().first) {
                result[monoStack.top().second] = i - monoStack.top().second;
                monoStack.pop();
            }
            monoStack.push({temperatures[i], i});
        }
        return result;
    }
};


// 单调栈，只存索引
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        stack<int> monoStack;
        vector<int> result(len, 0);

        for (int i = 0; i < len; i++) {
            while (!monoStack.empty() && temperatures[i] > temperatures[monoStack.top()]) {
                result[monoStack.top()] = i - monoStack.top();
                monoStack.pop();
            }
            monoStack.push(i);
        }
        return result;
    }
};