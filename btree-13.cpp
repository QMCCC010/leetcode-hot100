#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        int result = 0;
        vector<long long> targets;
        findTarget(root, targetSum, targets, result);
        return result;
    }

    void findTarget(TreeNode* root, int targetSum, vector<long long> targets, int& result) {
        if (root == nullptr) return;

        targets.push_back(targetSum);
        int len = targets.size();
        for (int i = 0; i < len; i++) {
            if (targets[i] == root->val) result++;
            targets[i] -= root->val;
        }

        findTarget(root->left, targetSum, targets, result);
        findTarget(root->right, targetSum, targets, result);
    }
};