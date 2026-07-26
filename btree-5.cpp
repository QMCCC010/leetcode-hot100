#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    // 最大直径的节点数
    int ans = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth (root);
        // 题目要求返回边数，边数等于节点数减 1
        return ans - 1;
    }

    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        // 对于没棵子树，其最大直径等于其 左孩子的最大深度 + 右孩子最大深度 + 1
        int left_ans = maxDepth(root->left);
        int right_ans = maxDepth(root->right);
        ans = std::max (ans, left_ans + right_ans + 1);

        // 对于以当前节点为根的子树，其最大深度为 左或右孩子的最大深度加 1 ，将其向上传递，供父节点计算
        return std::max (left_ans, right_ans) + 1;
    }
};