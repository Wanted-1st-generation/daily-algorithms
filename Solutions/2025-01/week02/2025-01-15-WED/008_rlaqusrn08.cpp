#include <bits/stdc++.h>	

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
    /*
    class Node {
        public:
            int data;
            Node *left;
            Node *right;
            Node(int d) {
                data = d;
                left = NULL;
                right = NULL;
            }
    };
    */

    void levelOrder(Node* root) {
        vector<int> V;
        queue<Node*> Q;
        Q.push(root);

        while (!Q.empty())
        {
            Node* cur = Q.front();
            Q.pop();
            V.push_back(cur->data);

            if (cur->left)
            {
                Q.push(cur->left);
            }
            if (cur->right)
            {
                Q.push(cur->right);
            }
        }

        for (int output : V)
        {
            cout << output << ' ';
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
