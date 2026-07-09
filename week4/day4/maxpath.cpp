#include <iostream>
#include <climits>
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
    int maxSum = INT_MIN;

    int solve(TreeNode* root) {
        if (root == nullptr)
            return 0;

        // Ignore negative paths
        int left = max(0, solve(root->left));
        int right = max(0, solve(root->right));

        // Update maximum path sum
        maxSum = max(maxSum, left + right + root->val);

        // Return maximum gain to parent
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxSum;
    }
};

int main() {

    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;

    cout << "Maximum Path Sum: "
         << obj.maxPathSum(root) << endl;

    return 0;
}