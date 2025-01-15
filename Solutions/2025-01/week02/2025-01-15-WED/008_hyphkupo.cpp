#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    Node* insert(Node* root, int data) {
        if (root == NULL) {
            return new Node(data);
        }
        else {
            Node* cur;
            if (data <= root->data) {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else {
                cur = insert(root->right, data);
                root->right = cur;
            }

            return root;
        }
    }

    void levelOrder(Node* root) {
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            cout << node->data << " ";

            if (node->left)
            {
                q.push(node->left);
            }

            if (node->right)
            {
                q.push(node->right);
            }
        }
    }

}; //End of Solution

int main() {

    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    std::cin >> t;

    while (t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.levelOrder(root);

    return 0;
}