
#include <iostream>
using namespace std;

// 노드 구조체
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Tree {
public:
    Tree() : root(nullptr) {}
    ~Tree() { deleteTree(root); }

    void addNode(int val);
    Node* Loweset_Common_Ancestor(int v1, int v2);

private:
    Node* root;

    Node* addNode(Node* node, int val);
    Node* Loweset_Common_Ancestor(Node* node, int v1, int v2);
    void deleteTree(Node* node);
};

void Tree::addNode(int val) {
    root = addNode(root, val);
}

Node* Tree::addNode(Node * node, int val) {
    if (node == nullptr) {
        return new Node(val);
    }
    if (val < node->data) {
        node->left = addNode(node->left, val);
    }
    else {
        node->right = addNode(node->right, val);
    }
    return node;
}

Node* Tree::Loweset_Common_Ancestor(int v1, int v2) {
    return Loweset_Common_Ancestor(root, v1, v2);
}

Node* Tree::Loweset_Common_Ancestor(Node * node, int v1, int v2) {
    if (node == nullptr) return nullptr;

    // 현재 노드가 v1 또는 v2와 같으면 LCA
    if (node->data == v1 || node->data == v2) {
        return node;
    }

    // 왼쪽과 오른쪽 서브트리를 탐색
    Node* leftLCA = Loweset_Common_Ancestor(node->left, v1, v2);
    Node* rightLCA = Loweset_Common_Ancestor(node->right, v1, v2);

    // 양쪽 서브트리에서 값이 발견되면 현재 노드가 LCA
    if (leftLCA != nullptr && rightLCA != nullptr) {
        return node;
    }

    // 그렇지 않으면 발견된 서브트리 반환
    return (leftLCA != nullptr) ? leftLCA : rightLCA;
}

void Tree::deleteTree(Node * node) {
    if (node == nullptr) return;

    // 재귀적으로 서브트리 삭제
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

int main() {
    Tree tree;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        tree.addNode(val);
    }

    int v1, v2;
    cin >> v1 >> v2;

    Node* lca = tree.Loweset_Common_Ancestor(v1, v2);
    if (lca != nullptr) {
        cout << "Loweset_Common_Ancestor: " << lca->data << endl;
    }

    return 0;
}
