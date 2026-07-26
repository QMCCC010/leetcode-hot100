#include <vector>
#include <unordered_map>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return nullptr;
        
        TreeNode* root = new TreeNode();
        root->val = preorder[0];

        if (preorder.size() == 1) return root;

        vector<int> left_inorder;
        vector<int> right_inorder;
        for (int i = 0; inorder[i] != preorder[0]; i++) left_inorder.push_back(inorder[i]);
        for (int j = left_inorder.size() + 1; j < inorder.size(); j++) right_inorder.push_back(inorder[j]);

        vector<int> left_preorder;
        vector<int> right_preorder;
        for (int i = 1; i < left_inorder.size() + 1; i++) left_preorder.push_back(preorder[i]);
        for (int j = left_inorder.size() + 1; j < preorder.size(); j++) right_preorder.push_back(preorder[j]);

        root->left = buildTree(left_preorder, left_inorder);
        root->right = buildTree(right_preorder, right_inorder);

        return root;
    }
};


// 哈希表优化
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> indexMap;
        for (int i = 0; i < inorder.size(); i++) indexMap[inorder[i]] = i;

        return build(preorder, inorder, indexMap, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& indexMap,
                    int preStart, int preEnd, int inStart, int inEnd) {
                        if (inStart > inEnd) return nullptr;

                        TreeNode* root = new TreeNode();
                        int rootVal = preorder[preStart];
                        root->val = rootVal;

                        // O(1)查找
                        int rootIndex = indexMap[rootVal];
                        int leftSize = rootIndex - inStart;

                        root->left = build(preorder, inorder, indexMap, preStart + 1, preStart + leftSize, inStart, rootIndex - 1);
                        root->right = build(preorder, inorder, indexMap, preStart + leftSize + 1, preEnd, rootIndex + 1, inEnd);

                        return root;
                    }
};