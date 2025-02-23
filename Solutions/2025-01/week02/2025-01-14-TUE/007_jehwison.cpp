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
        // �� Ʈ��
        if (!root) return;

        // ���� �Ÿ� �� ��� ������ ����
        map<int, int> topNodes;
        queue<pair<Node*, int>> q;
        
        // ��Ʈ ��� �߰�
        q.push({ root, 0 });

        while (!q.empty()) {
            auto currentNode = q.front();
            q.pop();
            Node* node = currentNode.first;
            int hd = currentNode.second;
            
            // ���� �Ÿ� �ʿ� ���� ��尡 ���� ��� �߰�
            if (topNodes.find(hd) == topNodes.end()) {
                topNodes[hd] = node->data;
            }

            // ���� �ڽ� ��尡 ������ ť�� �߰��ϰ� ���� �Ÿ� 1 ����
            if (node->left) {
                q.push({ node->left, hd - 1 });
            }

            // ������ �ڽ� ��尡 ������ ť�� �߰��ϰ� ���� �Ÿ� 1 ����
            if (node->right) {
                q.push({ node->right, hd + 1 });
            }
        }

        // ���
        for (const auto& pair : topNodes) {
            cout << pair.second << " ";
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
