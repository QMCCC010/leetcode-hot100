#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> leterMap = {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };
        vector<string> result;
        string group;
        backTracking(digits, 0, group, leterMap, result);
        return result;
    }

    void backTracking(string digits, int depth, string& group, vector<string>& leterMap, vector<string>& result) {
        if (depth >= digits.size()) {
            result.push_back(group);
            return;
        }

        int digit = digits[depth] - '0';
        if (digit >= 2 && digit <= 9) {
            for (int i = 0; i < leterMap[digit].size(); i++) {
                group.push_back(leterMap[digit][i]);
                backTracking(digits, depth + 1, group, leterMap, result);
                group.pop_back();
            }
        }
    }
};