#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len == 0 || len == 1) return 0;
        
        int result = 0;
        int minNum = prices[0];

        for (int i = 1; i < len; i++) {
            minNum = min(minNum, prices[i - 1]);
            result = max(result, prices[i] - minNum);
        }

        return result;
    }
};