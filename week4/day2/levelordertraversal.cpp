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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;

        if (!root)
            return ans;

        q.push(root);

        while (!q.empty()) {
            vector<int> level;
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();

                level.push_back(temp->val);

                if (temp->left)
                    q.push(temp->left);

                if (temp->right)
                    q.push(temp->right);
            }

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
    vector<vector<int>> result = obj.levelOrder(root);

    cout << "Level Order Traversal:\n";

    for (auto level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}