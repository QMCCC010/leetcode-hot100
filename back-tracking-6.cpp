#include <vector>
#include <string>
using namespace std;

// 额外isVisited数组记录已访问节点
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
        isVisited[x][y] = 1;
        pos++;
        if (pos == word.size()) {
            result = true;
            return;
        }

        if (x - 1 >= 0 && isVisited[x - 1][y] == 0 && board[x - 1][y] == word[pos])
            backTracking(board, word, x - 1, y, isVisited, pos, result);
        if (y - 1 >= 0 && isVisited[x][y - 1] == 0 && board[x][y - 1] == word[pos])
            backTracking(board, word, x, y - 1, isVisited, pos, result);
        if (x + 1 < board.size() && isVisited[x + 1][y] == 0 && board[x + 1][y] == word[pos])
            backTracking(board, word, x + 1, y, isVisited, pos, result);
        if (y + 1 < board[0].size() && isVisited[x][y + 1] == 0 && board[x][y + 1] == word[pos])
            backTracking(board, word, x, y + 1, isVisited, pos, result);
        
        pos--;
        isVisited[x][y] = 0;
    }
};

// 直接修改board数组
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
                    backTracking(board, word, i, j, pos, result);
                }
            }
        }
        return result;
    }

    void backTracking(vector<vector<char>>& board, string word, int x, int y, int& pos, bool& result) {
        char temp = board[x][y];
        board[x][y] = '#';
        pos++;
        if (pos == word.size()) {
            result = true;
            return;
        }

        if (x - 1 >= 0 && board[x - 1][y] == word[pos])
            backTracking(board, word, x - 1, y, pos, result);
        if (y - 1 >= 0 && board[x][y - 1] == word[pos])
            backTracking(board, word, x, y - 1, pos, result);
        if (x + 1 < board.size() && board[x + 1][y] == word[pos])
            backTracking(board, word, x + 1, y, pos, result);
        if (y + 1 < board[0].size() && board[x][y + 1] == word[pos])
            backTracking(board, word, x, y + 1, pos, result);
        
        pos--;
        board[x][y] = temp;
    }
};