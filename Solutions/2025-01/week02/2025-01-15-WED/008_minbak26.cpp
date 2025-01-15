#include <iostream>
#include <queue>
using namespace std;

// 노드 구조체
struct Node {
    int data;
    Node* left;
    Node* right;

    Node() {
        left = nullptr;
        right = nullptr;
    }
};

class Tree {
public:
    Tree() {
        root = nullptr;
    }
    ~Tree() {};

    void addNode(int val);
    void levelOrder();

private:
    Node* root;
};

void Tree::addNode(int val) {
    Node* newNode = new Node();
    newNode->data = val;

    if (root == nullptr) {
        root = newNode;
    }
    else {
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (temp->left == nullptr) {
                temp->left = newNode;
                break;
            }
            else {
                q.push(temp->left);
            }

            if (temp->right == nullptr) {
                temp->right = newNode;
                break;
            }
            else {
                q.push(temp->right);
            }
        }
    }
}

void Tree::levelOrder() {
    if (root == nullptr) {
        cout << "순회할 노드가 없습니다." << '\n';
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();
        cout << cur->data << ' ';

        if (cur->left != nullptr) {
            q.push(cur->left);
        }

        if (cur->right != nullptr) {
            q.push(cur->right);
        }
    }
    cout << '\n';
}

int main() {
    Tree tree;
    int t;
    cout << "노드 개수를 입력하세요: ";
    cin >> t;

    cout << "노드 값을 입력하세요: ";
    for (int i = 0; i < t; i++) {
        int val;
        cin >> val;
        tree.addNode(val);
    }

    cout << "레벨 순회 결과: ";
    tree.levelOrder();

    return 0;
}
