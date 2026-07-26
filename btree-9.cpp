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
    int result;
public:
    int kthSmallest(TreeNode* root, int k) {
        findSmallest(root, k);
        return result;
    }

    void findSmallest(TreeNode* root, int& k) {
        if (root == nullptr) {
            return;
        }

        findSmallest(root->left, k);
        k--;
        if (k == 0) {
            result = root->val;
            return;
        }
        findSmallest(root->right, k);
    }
};