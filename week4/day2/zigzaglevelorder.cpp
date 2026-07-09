#include <iostream>
#include <vector>
#include <queue>

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if (root == nullptr)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;

        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);

            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();

                // Decide index based on direction
                int index = leftToRight ? i : size - 1 - i;
                level[index] = temp->val;

                if (temp->left)
                    q.push(temp->left);

                if (temp->right)
                    q.push(temp->right);
            }

            leftToRight = !leftToRight;
            ans.push_back(level);
        }

        return ans;
    }
};

int main() {
    /*
            3
          /   \
         9     20
              /  \
             15   7
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;
    vector<vector<int>> result = obj.zigzagLevelOrder(root);

    cout << "Zigzag Level Order Traversal:\n";

    for (auto level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}