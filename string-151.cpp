#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> string_vector;
        string temp_str;

        for (char c : s) {
            if (c == ' ') {
                if (temp_str != "") string_vector.push_back(temp_str);
                temp_str = "";
            }
            else temp_str += c;
        }
        if (temp_str != "") string_vector.push_back(temp_str);
        s = "";
        for (int i = string_vector.size() - 1; i >= 0; i--) {
            s += string_vector[i];
            s += ' ';
        }
        s = s.substr(0, s.size() - 1);
        return s;
    }
};


// 双指针原地法
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        // 反转整个字符串
        reverse(s, 0, n - 1);

        int slow = 0, fast = 0;
        while (fast < n) {
            // 当fast指针找到一个单词
            if (s[fast] != ' ') {
                // 如果不是第一个单词，需要在单词之间添加一个空格
                if (slow != 0) s[slow++] = ' ';

                int start = slow;
                while (fast < n && s[fast] != ' ') {
                    // 从slow处开始填写fast扫描到的单词
                    s[slow++] = s[fast++];
                }
                // 扫描结束反转该单词
                reverse(s, start, slow - 1);
            }
            else fast++;
        }
        s.resize(slow);
        return s;
    }

    void reverse(string& s, int start, int end) {
        while (start < end) {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
};