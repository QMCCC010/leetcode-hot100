#include <string>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int len = s.size();
        int start = 0, end = k - 1;
        while (start < len) {
            if (end >= len) reverse(s, start, len - 1);
            else reverse(s, start, end);
            start += 2*k;
            end += 2*k;
        }
        return s;
    }

    void reverse (string& s, int start, int end) {
        while (start < end) {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
};