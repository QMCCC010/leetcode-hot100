#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        backTracking(candidates, 0, path, target, result);
        return result;
    }

    void backTracking(vector<int>& candidates, int depth, vector<int>& path, int target, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(path);
            return;
        }
        if (depth == candidates.size()) return;

        for (int k = 0; k * candidates[depth] <= target; k++) {
            for (int i = 0; i < k; i++) path.push_back(candidates[depth]);
            backTracking(candidates, depth + 1, path, target - k * candidates[depth], result);
            for (int i = 0; i < k; i++) path.pop_back();
        }
    }
};