#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        unordered_map<char, int> endPos;
        int start = 0;
        int end = 0;
        vector<int> result;
        int len = s.size();

        for (int i = 0; i < len; i++) {
            endPos[s[i]] = i;
        }

        for (int i = 0; i < len; i++) {
            end = max (end, endPos[s[i]]);

            if (i == end) {
                result.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return result;
    }
};