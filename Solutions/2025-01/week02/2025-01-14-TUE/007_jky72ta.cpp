#include <queue>
#include <deque>
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

    void topView(Node* root) {
        deque<int> deq;
        queue<pair<Node*, int>> que;
        deq.push_back(root->data);
        quePush(que, root, 0);
        int left = -1;
        int right = 1;
        while (!que.empty())
        {
            int count = que.size();
            bool flag = false;
            for (int i = 0; i < count; ++i)
            {
                pair<Node*, int> nd = que.front();
                Node* n = nd.first;
                int dist = nd.second;
                que.pop();
                if (dist < 0 && left == dist)
                {
                    left = left - 1;
                    deq.push_front(n->data);
                }
                else if (dist > 0 && right == dist)
                {
                    if (flag == true)
                    {
                        deq.back() = n->data;
                    }
                    else {
                        deq.push_back(n->data);
                        flag = true;
                    }
                }
                quePush(que, n, dist);
            }
            if (flag)
            {
                right = right + 1;
            }
        }
        deque<int>::iterator end = deq.end();
        --end;
        for (deque<int>::iterator begin = deq.begin(); begin != end; begin++)
        {
            std::cout << (*begin) << " ";
        }
        std::cout << (*end);
    }

private:
    void quePush(queue<pair<Node*, int>>& que, Node* root, int i)
    {
        if (root->left != nullptr)
        {
            que.push(make_pair(root->left, i - 1));
        }
        if (root->right != nullptr)
        {
            que.push(make_pair(root->right, i + 1));
        }
    }

};

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
