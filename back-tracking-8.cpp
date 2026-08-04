#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<int> pos;
        backTracking(n, 0, pos, result);
        return result;
    }

    void backTracking(const int n, int depth, vector<int>& pos, vector<vector<string>>& result) {
        if (depth >= n) {
            string tempStr = "";
            for (int i = 0; i < n; i++) tempStr += '.';
            vector<string> path (n, tempStr);
            for (int i = 0; i < n; i++) path[i][pos[i]] = 'Q';
            result.push_back(path);
            return;
        }

        for (int i = 0; i < n; i++) {
             if (check(pos, depth, i)) {
                pos.push_back(i);
                backTracking(n, depth + 1, pos, result);
                pos.pop_back();
             }
        }
    }

    bool check(vector<int>& pos, int depth, int currPos) {
        for (int i = 0; i < pos.size(); i++) {
            if (pos[i] == currPos || pos[i] - i == currPos - depth || pos[i] + i == currPos + depth)
                return false;
        }
        return true;
    }
};