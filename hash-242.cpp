#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        // 记录每个字母出现的次数
        unordered_map<char, int> sMap;
        unordered_map<char, int> tMap;

        for (char c : s) {
            sMap[c]++;
        }
        for (char c : t) {
            tMap[c]++;
        }

        for (char c : s) {
            if (sMap.count(c) != tMap.count(c) || sMap[c] != tMap[c]) return false;
        }
        for (char c :t) {
            if (sMap.count(c) != tMap.count(c) || sMap[c] != tMap[c]) return false;
        }
        return true;
    }
};


// 哈希一次遍历
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> countMap;
        
        for (int i = 0; i < s.size(); i++) {
            countMap[s[i]]++;
            countMap[t[i]]--;
        }

        for (const auto& myPair : countMap) {
            if (myPair.second != 0) return false;
        }
        return true;
    }
};


// 数组法
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int letter[26] = {0};

        for (int i = 0; i < s.size(); i++) {
            letter[s[i] - 'a']++;
            letter[t[i] - 'a']--;
        }
        
        for (int count : letter) {
            if (count != 0) return false;
        }
        return true;
    }
};