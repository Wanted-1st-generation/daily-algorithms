#include <iostream>
#include <vector>

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

    void topView(Node* root) {
        vector<int> v;

        Node* cur = root;
        while (cur->left)
        {
            v.push_back((cur->left)->data);
            cur = cur->left;
        }

        v.push_back(root->data);

        Node* cur2 = root;
        while (cur2->right)
        {
            v.push_back((cur2->right)->data);
            cur2 = cur2->right;
        }

        for (int i = 0; i < v.size(); ++i)
        {
            cout << v[i] << " ";
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

    myTree.topView(root);

    return 0;
}