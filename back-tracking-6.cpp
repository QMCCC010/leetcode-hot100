#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) return false;
        
        bool result = false;
        int row = board.size();
        int col = board[0].size();
        int pos = 0;

        // 记录某个位置是否已经访问过
        vector<vector<char>> isVisited(row, vector<char>(col, 0));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == word[pos]) {
                    backTracking(board, word, i, j, isVisited, pos, result);
                }
            }
        }
        return result;
    }

    void backTracking(vector<vector<char>>& board, string word, int x, int y, vector<vector<char>>& isVisited, int& pos, bool& result) {
        if (board[x][y] == word[pos]) {
            pos++;
            if (pos >= word.size()) {
                result = true;
                return;
            }

            if (x - 1 >= 0 && isVisited[x - 1][y] == 0) {
                isVisited[x - 1][y] = 1;
                backTracking(board, word, x- 1, y, isVisited, pos, result);
                isVisited[x - 1][y] = 0;
            }
            if (x + 1 < board.size() && isVisited[x + 1][y] == 0) {
                isVisited[x + 1][y] = 1;
                backTracking(board, word, x + 1, y, isVisited, pos, result);
                isVisited[x + 1][y] = 0;
            }
            if (y - 1 >= 0 && isVisited[x][y - 1] == 0) {
                isVisited[x][y - 1] = 1;
                backTracking(board, word, x, y - 1, isVisited, pos, result);
                isVisited[x][y - 1] = 0;
            }
            if (y + 1 < board[0].size() && isVisited[x][y + 1] == 0) {
                isVisited[x][y + 1] = 1;
                backTracking(board, word, x, y + 1, isVisited, pos, result);
                isVisited[x][y + 1] = 0;
            }
            pos--;
        }
    }
};