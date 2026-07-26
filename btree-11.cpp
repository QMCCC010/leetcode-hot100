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
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        vector<TreeNode*> node_arr;
        preorderTraversal(root, node_arr);

        int len = node_arr.size();
        for (int i = 0; i < len - 1; i++) {
            node_arr[i]->left = nullptr;
            node_arr[i]->right = node_arr[i + 1];
        }

    }

    void preorderTraversal(TreeNode* root, vector<TreeNode*>& node_arr) {
        if (root == nullptr) return;

        node_arr.push_back(root);
        preorderTraversal(root->left, node_arr);
        preorderTraversal(root->right, node_arr);
    }
};

// 原地算法
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;

        flatten(root->left);
        flatten(root->right);

        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = nullptr;

        TreeNode* curr = root;
        while (curr->right != nullptr) curr = curr->right;
        curr->right = temp;
    }
};