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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> tree_queue;
        vector<vector<int>> result;

        if (root != nullptr) {
            tree_queue.push(root);
            while (!tree_queue.empty()) {
                // 记录每一层的数量
                int layer_size = tree_queue.size();
                // 保存这一层的结果
                vector<int> curr_layer;
                while (layer_size > 0) {
                    // 记录当前层的结果
                    TreeNode* node = tree_queue.front();
                    curr_layer.push_back(node->val);

                    // 将左右孩子加入队列(非空指针不入队)
                    if (node->left != nullptr) tree_queue.push(node->left);
                    if (node->right != nullptr) tree_queue.push(node->right);
                    tree_queue.pop();
                    layer_size--;
                }
                result.push_back(curr_layer);
            }
        }
        return result;
    }
};