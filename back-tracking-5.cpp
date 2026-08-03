#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string path;
        backTracking(n, 0, 0, path, result);
        return result;
    }

    void backTracking(int n, int lc, int rc, string& path, vector<string>& result) {
        if (lc == n && rc == n) {
            result.push_back(path);
            return;
        }

        // 选择放左括号
        if (lc < n) {
            path.push_back('(');
            backTracking(n, lc + 1, rc, path, result);
            path.pop_back();
        }

        // 选择放右括号
        if (lc > rc) {
            path.push_back(')');
            backTracking(n, lc, rc + 1, path, result);
            path.pop_back();
        }
    }
};