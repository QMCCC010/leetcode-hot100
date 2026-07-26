#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int slow = 0;
        int fast = height.size() - 1;
        int max_capacity = 0;
        while (slow < fast) {
            max_capacity = max(max_capacity, (fast - slow) * min(height[slow], height[fast]));
            if (height[slow] < height[fast]) slow++;
            else fast--;
        }
        return max_capacity;
    }
};


int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    Solution sloution;
    int max_capacity = sloution.maxArea(height);
    cout << max_capacity << endl;
}