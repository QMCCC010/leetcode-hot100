#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int pos = 0;
        return recurStr(s, pos);
    }

    string recurStr(string s, int& pos) {
        string result;
        int len = s.size();

        while (pos < len && s[pos] != ']') {
            if (isalpha(s[pos])) {
                result += s[pos];
                pos++;
            }
            else if (isdigit(s[pos])) {
                int counts = 0;
                while (pos < len && isdigit(s[pos])) {
                    counts = 10*counts + (s[pos] - '0');
                    pos++;
                }

                // 跳过'['
                pos++;

                // 寻找内层子串
                string innerStr = recurStr(s, pos);

                // 跳过']'
                pos++;

                // 循环拼接
                for (int i = 0; i < counts; i++) result += innerStr;
            }
        }
        return result;
    }
};