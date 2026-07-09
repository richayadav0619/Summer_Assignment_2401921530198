#include <iostream>
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
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root != nullptr) {
            if (root->val == val)
                return root;
            else if (val < root->val)
                root = root->left;
            else
                root = root->right;
        }
        return nullptr;
    }
};

int main() {
    /*
             4
           /   \
          2     7
         / \
        1   3
    */

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution obj;

    int target = 2;

    TreeNode* result = obj.searchBST(root, target);

    if (result != nullptr) {
        cout << "Value found: " << result->val << endl;
    } else {
        cout << "Value not found." << endl;
    }

    return 0;
}