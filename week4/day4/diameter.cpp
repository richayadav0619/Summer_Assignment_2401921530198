#include <iostream>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    int diameter = 0;

    int height(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        // Update maximum diameter
        diameter = max(diameter, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
    }
};

int main() {

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution obj;

    cout << "Diameter: " << obj.diameterOfBinaryTree(root) << endl;

    return 0;
}