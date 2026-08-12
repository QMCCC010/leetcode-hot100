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
        int len = s.size();
        // 反转整个字符串
        reverse(s, 0, len - 1);

        int startIdx = 0, endIdx = len - 1;
        while (startIdx < endIdx) {
            if (s[startIdx] != ' ' && s[endIdx] != ' ') break;
            if (s[startIdx] == ' ') startIdx++;
            if (s[endIdx] == ' ') endIdx--;
        }
        // 反转每个单词
        int start = startIdx, end = start;
        while (end <= endIdx) {
            if (s[end] == ' ') {
                reverse(s, start, end - 1);
                start = end;
                while (s[end] == ' ') end++;
                s.erase(start + 1, end - start - 1);
                end = ++start;
                endIdx -= end - start - 1;
            }
            else end++;
        }
        reverse(s, start, endIdx);

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