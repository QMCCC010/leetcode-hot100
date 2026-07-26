#include <vector>
using namespace std;


// 不修改原数组，深度优先
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1' && visited[i][j] == false) {
                    result++;
                    visited[i][j] == true;
                    extendIslands(grid, visited, i, j);
                }
                visited[i][j] == true;
            }
        }
        return result;
    }

    void extendIslands(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {     
        if (i - 1 >= 0 && grid[i - 1][j] == '1' && visited[i - 1][j] == false) {
            visited[i - 1][j] = true;
            extendIslands(grid, visited, i - 1, j);
        }

        if (j - 1 >= 0 && grid[i][j - 1] == '1' && visited[i][j - 1] == false) {
            visited[i][j - 1] = true;
            extendIslands(grid, visited, i, j - 1);
        }
        
        if (i + 1 < grid.size() && grid[i + 1][j] == '1' && visited[i + 1][j] == false) {
            visited[i + 1][j] = true;
            extendIslands(grid, visited, i + 1, j);
        }
        if (j + 1 < grid[0].size() && grid[i][j + 1] == '1' && visited[i][j + 1] == false) {
            visited[i][j + 1] = true;
            extendIslands(grid, visited, i, j + 1);
        }
        return;
    }
};

#include <queue>
// 广度优先
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        queue<pair<int, int>> neighbors;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1' && visited[i][j] == false) {
                    result++;
                    visited[i][j] = true;
                    neighbors.push({i, j});

                    while (!neighbors.empty()) {
                        pair front = neighbors.front();
                        neighbors.pop();

                        if (front.first - 1 >= 0 && grid[front.first - 1][front.second] == '1' && visited[front.first-1][front.second] == false) {
                            visited[front.first - 1][front.second] = 1;
                            neighbors.push({front.first - 1, front.second});
                        }
                        if (front.second - 1 >= 0 && grid[front.first][front.second - 1] == '1' &&visited[front.first][front.second - 1] == false) {
                            visited[front.first][front.second - 1] = true;
                            neighbors.push({front.first, front.second - 1});
                        }
                        if (front.first + 1 < row && grid[front.first + 1][front.second] == '1' &&visited[front.first + 1][front.second] == false) {
                            visited[front.first + 1][front.second] = true;
                            neighbors.push({front.first + 1, front.second});
                        }
                        if (front.second + 1 < col && grid[front.first][front.second + 1] == '1' &&visited[front.first][front.second + 1] == false) {
                            visited[front.first][front.second + 1] = true;
                            neighbors.push({front.first, front.second + 1});
                        }
                    }
                }
            }
        }
        return result;
    }
};