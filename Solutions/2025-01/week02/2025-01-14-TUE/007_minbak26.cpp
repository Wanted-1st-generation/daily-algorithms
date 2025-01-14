#include <iostream>
#include <map>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    int level;
    Node* left;
    Node* right;

    Node(int data)
        : data(data), level(0), left(nullptr), right(nullptr) {
    }
};

// Top View를 출력하는 함수
void coutTopView(Node* root) {
    if (!root) return;

    // 수평 거리(HD)를 키로, 노드 값을 값으로 저장하는 맵
    map<int, int> topViewMap;

    // BFS 탐색을 위한 큐 (노드, 수평 거리)
    queue<pair<Node*, int>> q;
    q.push({ root, 0 });

    while (!q.empty()) {
        auto current = q.front();
        q.pop();

        Node* currNode = current.first;
        int hd = current.second;

        // 처음 만나는 수평 거리의 노드만 삽입
        if (topViewMap.find(hd) == topViewMap.end()) {
            topViewMap[hd] = currNode->data;
        }

        // 왼쪽 자식 
        if (currNode->left) {
            q.push({ currNode->left, hd - 1 });
        }

        // 오른쪽 자식
        if (currNode->right) {
            q.push({ currNode->right, hd + 1 });
        }
    }

    // 결과 출력
    for (auto it : topViewMap) {
        cout << it.second << " ";
    }
    cout << endl;
}

// 노드를 추가하는 함수
Node* insertNode(Node* root, int data) {
    if (!root) {
        return new Node(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

int main() {
    int t = 0; // 트리의 노드 개수
    cin >> t;

    Node* root = nullptr;
    for (int i = 0; i < t; i++) {
        int num = 0;
        cin >> num;
        root = insertNode(root, num);
    }

    cout << "Top View of the Tree: ";
    coutTopView(root);

    return 0;
}
