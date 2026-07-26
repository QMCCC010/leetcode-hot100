#include <vector>
#include <queue>
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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> tree_queue;
        vector<int> result;

        if (root != nullptr) {
            tree_queue.push(root);

            while (!tree_queue.empty()) {
                int layer_size = tree_queue.size();
                while (layer_size > 0) {
                    TreeNode* curr_node = tree_queue.front();
                    if (layer_size == 1) result.push_back(curr_node->val);

                    tree_queue.pop();
                    layer_size--;
                    if (curr_node->left) tree_queue.push(curr_node->left);
                    if (curr_node->right) tree_queue.push(curr_node->right);
                }
            }
        }
        return result;
    }
};