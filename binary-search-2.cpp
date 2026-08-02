#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int row = matrix.size();
        int col = matrix[0].size();
        int slow = 0, fast = row - 1;

        while (slow <= fast) {
            int mid = (slow + fast) / 2;
            if (matrix[mid][0] == target) return true;
            else if (matrix[mid][0] > target) fast = mid - 1;
            else slow = mid + 1;
        }

        int target_row = fast;
        if (target_row < 0 || target_row >= row) return false;
        slow = 0;
        fast = col - 1;
        while (slow <= fast) {
            int mid = (slow + fast) / 2;
            if (matrix[target_row][mid] == target) return true;
            else if (matrix[target_row][mid] > target) fast = mid - 1;
            else slow = mid + 1;
        }

        return false;
    }
};
