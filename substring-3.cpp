#include <string>
#include <unordered_map>
#include <limits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        string result = "";
        int len_s = s.size();
        int len_t = t.size();

        if (len_s < len_t) return result;
        unordered_map<char, int> need;
        unordered_map<char, int> window;

        for (char c : t) {
            need[c] += 1;
            window[c] = 0;
        }

        int valid = 0;
        int left = 0, right = 0;
        int start = 0, sub_len = numeric_limits<int>::max();
        while(right < len_s) {
            char c = s[right];
            right++;

            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }

            while (valid == need.size()) {
                if (right - left < sub_len) {
                    start = left;
                    sub_len = right - left;
                }

                if (need.count(s[left])) {
                    window[s[left]] -= 1;
                    if (window[s[left]] < need[s[left]]) valid--;
                }
                left++;
            }

        }
        if (sub_len != numeric_limits<int>::max()) result = s.substr(start, sub_len);
        return result;
    }
};