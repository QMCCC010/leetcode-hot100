#include <vector>
using namespace std;

enum class Direction {
    right,
    down,
    left,
    up
};

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        // 边界
        int up_bound = 0, down_bound = n - 1;
        int left_bound = 0, right_bound = n - 1;
        // 方向
        Direction direction = Direction::right;
        // 位置
        int x = 0, y = 0;
        // 填入位置的数字
        int num = 1;

        while (num <= n*n) {
            result[x][y] = num++;
            switch (direction) {
                case Direction::right:
                    if (y == right_bound) {
                        x++;
                        up_bound++;
                        direction = Direction::down;
                    }
                    else y++;
                case Direction::down:
                    if (x == down_bound) {
                        y--;
                        right_bound--;
                        direction = Direction::left;
                    }
                    else x++;
                case Direction::left:
                    if (y == left_bound) {
                        x--;
                        down_bound--;
                        direction = Direction::up;
                    }
                    else y--;
                case Direction::up:
                    if (x == up_bound) {
                        y++;
                        left_bound++;
                        direction = Direction::right;
                    }
                    else x--;
            }
        }
        return result;
    }
};