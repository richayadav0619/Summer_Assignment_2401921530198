#include <iostream>
#include <climits>

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
    bool solve(TreeNode* root, long long minVal, long long maxVal) {
        if (root == nullptr)
            return true;

        if (root->val <= minVal || root->val >= maxVal)
            return false;

        return solve(root->left, minVal, root->val) &&
               solve(root->right, root->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};

int main() {

    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    Solution obj;

    if (obj.isValidBST(root))
        cout << "Valid BST" << endl;
    else
        cout << "Invalid BST" << endl;

    return 0;
}