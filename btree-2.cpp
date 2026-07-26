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
    int max_depth = 0;
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return max_depth;
        else {
            int curr_depth = 1;
            max_depth = curr_depth;
            findDepth(curr_depth, root);
            return max_depth;
        }
    }

    void findDepth(int &curr_depth, TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        else if (root->left == nullptr && root->right == nullptr) {
            max_depth = std::max (max_depth, curr_depth);
        }
        else {
            if (root->left != nullptr) {
                curr_depth++;
                findDepth(curr_depth, root->left);
                curr_depth--;
            }
            if (root->right != nullptr) {
                curr_depth++;
                findDepth(curr_depth, root->right);
                curr_depth--;
            }
        }
    }
};