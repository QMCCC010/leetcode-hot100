#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int result = -1;
        int row = grid.size();
        int col = grid[0].size();

        // 腐烂橘子队列
        queue<pair<int, int>> rotted_oranges;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 2) {
                    rotted_oranges.push({i, j});
                }
            }
        }

        // 层序遍历，记录层数，本质广度优先搜索
        while (!rotted_oranges.empty()) {
            result++;
            int size = rotted_oranges.size();
            while (size > 0) {
                auto top = rotted_oranges.front();
                rotted_oranges.pop();

                if (top.first - 1 >= 0 && grid[top.first - 1][top.second] == 1) {
                    grid[top.first - 1][top.second] = 2;
                    rotted_oranges.push({top.first - 1, top.second});
                }
                if (top.first + 1 < row && grid[top.first + 1][top.second] == 1) {
                    grid[top.first + 1][top.second] = 2;
                    rotted_oranges.push({top.first + 1, top.second});
                }
                if (top.second - 1 >= 0 && grid[top.first][top.second - 1] == 1) {
                    grid[top.first][top.second - 1] = 2;
                    rotted_oranges.push({top.first, top.second - 1});
                }
                if (top.second + 1 < col && grid[top.first][top.second + 1] == 1) {
                    grid[top.first][top.second + 1] = 2;
                    rotted_oranges.push({top.first, top.second + 1});
                }
            }
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) return -1;
            }
        }
        return result;
    }
};