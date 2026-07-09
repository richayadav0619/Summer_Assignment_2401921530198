#include <iostream>
#include <queue>
#include <string>
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

class Codec {
public:
    string serialize(TreeNode* root) {
        if (root == nullptr)
            return "N,";

        return to_string(root->val) + "," +
               serialize(root->left) +
               serialize(root->right);
    }

    TreeNode* deserialize(string data) {
        queue<string> q;
        string temp = "";

        for (char ch : data) {
            if (ch == ',') {
                q.push(temp);
                temp = "";
            } else {
                temp += ch;
            }
        }

        return buildTree(q);
    }

private:
    TreeNode* buildTree(queue<string>& q) {
        string val = q.front();
        q.pop();

        if (val == "N")
            return nullptr;

        TreeNode* root = new TreeNode(stoi(val));
        root->left = buildTree(q);
        root->right = buildTree(q);

        return root;
    }
};

int main() {
    /*
            1
           / \
          2   3
             / \
            4   5
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Codec obj;

    string s = obj.serialize(root);
    cout << "Serialized Tree: " << s << endl;

    TreeNode* newRoot = obj.deserialize(s);

    cout << "Root after Deserialization: " << newRoot->val << endl;

    return 0;
}