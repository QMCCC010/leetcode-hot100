#include <vector>
using namespace std;


// 用第一行和第一列纪录位置（i, j）是否为零，最后再单独处理第一行和第一列
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool oneRowHasZero = false;
        bool oneColHasZero = false;

        // 判断第一行和第一列是否有零
        for (int i = 0; i < n; i++) {
            if (matrix[0][i] == 0) oneRowHasZero = true;
        }
        for (int j = 0; j < m; j++) {
            if (matrix[j][0] == 0) oneColHasZero = true;
        }

        // 找剩余零的位置
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // 行置零
        for (int i = 1; i < m; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 0; j < n; j++) matrix[i][j] = 0;
            }
        }
        // 列置零
        for (int i = 1; i < n; i++) {
            if (matrix[0][i] == 0) {
                for (int j = 0; j < m; j++) matrix[j][i] = 0;
            }
        }

        // 处理第一行和第一列
        if (oneRowHasZero) {
            for (int i = 0; i < n; i++) matrix[0][i] = 0;
        }
        if (oneColHasZero) {
            for (int i = 0; i < m; i++) matrix[i][0] = 0;
        }
    }
};