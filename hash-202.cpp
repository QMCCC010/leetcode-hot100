#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> existNums;
        int num = n;

        while(existNums.count(num) == 0) {
            existNums.insert(num);
            num = getNextNum(num);
        }
        if (num == 1) return true;
        else return false;
    }

    int getNextNum(int n) {
        int sum = 0;

        while (n > 0) {
            int digit = n % 10; // 取个位
            sum += digit * digit;
            n = n / 10; // 去掉个位
        }
        return sum;
    }
};