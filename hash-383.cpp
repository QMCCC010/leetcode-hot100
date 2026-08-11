#include <string>
#include <unordered_map>
using namespace std;

// 哈希
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> letters;

        for (char c : magazine) letters[c]++;

        for (char c : ransomNote) {
            letters[c]--;
            if (letters[c] < 0) return false;
        }
        return true;
    }
};


// 数组
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // 提前剪枝
        if (ransomNote.size() > magazine.size()) return false;
        int letters[26] = {0};

        for (char c : magazine) letters[c - 'a']++;

        for (char c : ransomNote) {
            if (--letters[c - 'a'] < 0) return false;
        }
        return true;
    }
};