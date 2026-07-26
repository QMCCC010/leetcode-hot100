#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> appear_nums;
        int slow = 0;
        int max_length = 0;
        int len = s.length();
        for (int fast = 0; fast < len; fast++) {
            appear_nums[s[fast]] += 1;
            while(appear_nums[s[fast]] > 1) {
                appear_nums[s[slow]] -= 1;
                slow++;
            }
            max_length = max(max_length, fast - slow + 1);
        }
        return max_length;
    }
};

int main() {
    Solution solution;
    string s = "tmmzuxt";
    int result = solution.lengthOfLongestSubstring(s);
    cout << result << endl;
}