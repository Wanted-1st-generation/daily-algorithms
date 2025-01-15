#include<bits/stdc++.h>

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

    void topView(Node* root) {
        map<int, int> M;
        queue<pair<int, Node*>> Q;
        Q.push({ 0, root });

        while (!Q.empty())
        {
            pair<int, Node*> cur = Q.front();
            Q.pop();

            if (M.find(cur.first) == M.end())
            {
                M.insert({ cur.first, cur.second->data });
            }

            if (cur.second->left)
            {
                Q.push({ cur.first - 1, cur.second->left });
            }
            if (cur.second->right)
            {
                Q.push({ cur.first + 1, cur.second->right });
            }
        }

        for (auto iter : M)
        {
            cout << iter.second << ' ';
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
