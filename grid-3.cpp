#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses == 0 || prerequisites.empty()) return true;

        // 建立邻接表
        vector<vector<int>> graph(numCourses);
        // 记录每个点的入度
        vector<int> inVec(numCourses, 0);
        for (auto& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            inVec[pre[0]]++;
        }
        // 用队列记录度为0的节点
        queue<int> zero_q;
        for (int i = 0; i < numCourses; i++) {
            if (inVec[i] == 0) zero_q.push(i);
        }


        while (!zero_q.empty()) {
            int root = zero_q.front();
            zero_q.pop();
            
            for (int vertex : graph[root]) {
                inVec[vertex]--;
                if (inVec[vertex] == 0) zero_q.push(vertex);
            }
        }
        for (int i = 0; i < numCourses; i++) {
            if (inVec[i] != 0) return false;
        }
        return true;
    }
};