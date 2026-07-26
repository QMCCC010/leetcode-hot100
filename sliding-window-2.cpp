#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int s_len = s.size(), p_len = p.size();
        vector<int> result;

        if (s_len < p_len) return result;

        vector<int> need(26, 0), window(26, 0);

        // 记录 p 中所需字符出现的频数
        for (char c : p) {
            need[c - 'a']++;
        }

        // 初始化 window 窗口
        for (int i = 0; i < p_len; i++) {
            window[s[i] - 'a']++;
        }

        for (int left = 0, right = p_len - 1; right < s_len; left++, right++) {
            if (window == need) {
                result.push_back(left);
            }

            window[s[left]- 'a']--;
            if (right != s_len - 1) window[s[right + 1] - 'a']++;
        }

        return result;
    }
};