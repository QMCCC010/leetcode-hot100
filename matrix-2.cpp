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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty() || matrix[0].empty()) return result;
        
        int row = matrix.size();
        int col = matrix[0].size();

        int up_board = 0, left_board = 0;
        int down_board = row - 1, right_board = col - 1;

        int counts = 0;
        int size = row * col;

        // 记录当前位置和方向
        Direction direction = Direction::right;
        pair<int, int> pos = {0, 0};

        while (counts < size) {
            switch (direction) {
                case Direction::right:
                    result.push_back(matrix[pos.first][pos.second]);
                    if (pos.second == right_board) {
                        up_board++;
                        pos.first++;
                        direction = Direction::down;
                    }
                    else pos.second++;
                    break;
                case Direction::down:
                    result.push_back(matrix[pos.first][pos.second]);
                    if (pos.first == down_board) {
                        right_board--;
                        pos.second--;
                        direction = Direction::left;
                    }
                    else pos.first++;
                    break;
                case Direction::left:
                    result.push_back(matrix[pos.first][pos.second]);
                    if (pos.second == left_board) {
                        down_board--;
                        pos.first--;
                        direction = Direction::up;
                    }
                    else pos.second--;
                    break;
                case Direction::up:
                    result.push_back(matrix[pos.first][pos.second]);
                    if (pos.first == up_board) {
                        left_board++;
                        pos.second++;
                        direction = Direction::right;
                    }
                    else pos.first--;
                    break;
            }
            counts++;
        }
        return result;
    }
};