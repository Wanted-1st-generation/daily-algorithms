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
        // 빈 트리
        if (!root) return;

        // 수평 거리 및 노드 데이터 저장
        map<int, int> topNodes;
        queue<pair<Node*, int>> q;
        
        // 루트 노드 추가
        q.push({ root, 0 });

        while (!q.empty()) {
            auto currentNode = q.front();
            q.pop();
            Node* node = currentNode.first;
            int hd = currentNode.second;
            
            // 수평 거리 맵에 현재 노드가 없는 경우 추가
            if (topNodes.find(hd) == topNodes.end()) {
                topNodes[hd] = node->data;
            }

            // 왼쪽 자식 노드가 있으면 큐에 추가하고 수평 거리 1 감소
            if (node->left) {
                q.push({ node->left, hd - 1 });
            }

            // 오른쪽 자식 노드가 있으면 큐에 추가하고 수평 거리 1 증가
            if (node->right) {
                q.push({ node->right, hd + 1 });
            }
        }

        // 출력
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
