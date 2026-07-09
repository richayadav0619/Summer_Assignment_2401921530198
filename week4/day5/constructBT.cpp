#include <iostream>
#include <vector>
#include <unordered_map>
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
    unordered_map<int, int> mp;
    int preIndex = 0;

    TreeNode* build(vector<int>& preorder, vector<int>& inorder,
                    int inStart, int inEnd) {

        if (inStart > inEnd)
            return nullptr;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int pos = mp[rootVal];

        root->left = build(preorder, inorder, inStart, pos - 1);
        root->right = build(preorder, inorder, pos + 1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        return build(preorder, inorder, 0, inorder.size() - 1);
    }
};

// Inorder traversal for verification
void inorderTraversal(TreeNode* root) {
    if (root == nullptr)
        return;

    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {

    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution obj;

    TreeNode* root = obj.buildTree(preorder, inorder);

    cout << "Inorder Traversal of Constructed Tree: ";
    inorderTraversal(root);

    return 0;
}