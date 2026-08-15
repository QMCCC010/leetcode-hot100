#include <string>
using namespace std;

// 暴力解法
class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.size();
        int len2 = needle.size();

        for (int i = 0; i <= len1 - len2; i++) {
            // 枚举每个起点
            int j = i, k = 0;
            while (k < len2 && haystack[j] == needle[k]){
                j++;
                k++;
            }
            if (k == len2) return i;
        }
        return -1;
    }
};