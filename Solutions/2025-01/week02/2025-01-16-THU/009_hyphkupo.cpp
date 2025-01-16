#include <iostream>

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

    /*The tree node has data, left child and right child
    class Node {
        int data;
        Node* left;
        Node* right;
    };

    */

    Node* lca(Node* root, int v1, int v2) {
        int min, max;
        if (v1 > v2)
        {
            min = v2;
            max = v1;
        }
        else
        {
            min = v1;
            max = v2;
        }

        // LCA가 나올 때까지 루트부터 차례대로 순회
        while (root)
        {
            if (root->data < max && root->data > min)
            {
                return root;
            }

            else if (root->data < min)
            {
                root = root->right;
            }

            else if (root->data > max)
            {
                root = root->left;
            }

            else
            {
                return root;
            }
        }

        return root;
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

    int v1, v2;
    std::cin >> v1 >> v2;

    Node* ans = myTree.lca(root, v1, v2);

    std::cout << ans->data;

    return 0;
}