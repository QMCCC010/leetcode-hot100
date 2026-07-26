#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        int len = intervals.size();
        
        sort(intervals.begin(), intervals.end());
        result.push_back(intervals[0]);

        for (int i = 1; i < len; i++) {
            vector<int> &last = result.back();
            vector<int> &curr = intervals[i];

            if (curr[0] > last[1]) result.push_back(curr);
            else if (curr[0] <= last[1] && curr[1] > last[1]) last[1] = curr[1];
        }

        return result;
    }
};