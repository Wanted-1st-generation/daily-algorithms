#include <bits/stdc++.h>	


using namespace std;

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

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
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

#include <iostream>
#include <queue>

    void levelOrder(Node * root) {
        queue<int> answer;
        queue<Node*> que;
        que.push(root);
        while (!que.empty())
        {
            int count = que.size();
            for (int i = 0; i < count; ++i)
            {
                Node* nd = que.front();
                answer.push(nd->data);
                que.pop();
                if (nd->left != nullptr)
                {
                    que.push(nd->left);
                }
                if (nd->right != nullptr)
                {
                    que.push(nd->right);
                }
            }
        }
        while (!answer.empty())
        {
            std::cout << answer.front() << " ";
            answer.pop();
        }
        std::cout << std::endl;
    }

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
	myTree.levelOrder(root);
    return 0;
}
//6
//1 2 5 3 6 4
//1 2 5 3 6 4