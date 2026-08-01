#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        
        int row = matrix.size();
        int col = matrix.size();

        for (int i = 0; i < row; i++) {
            for (int j = i + 1; j < col; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col / 2; j++) {
                swap(matrix[i][j], matrix[i][col - j - 1]);
            }
        }
    }
};