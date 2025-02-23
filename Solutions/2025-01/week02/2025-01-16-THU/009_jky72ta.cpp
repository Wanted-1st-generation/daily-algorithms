#include <iostream>
#include <queue>

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

        bool search(Node *root, int key)
        {
            return (searchS(root, key) != nullptr);
        }

        Node *lca(Node *root, int v1,int v2)
        {
            return (LCA(root, v1, v2));
        }
    private:
        Node* searchS(Node *node, int key)
        {
            if (node == nullptr || node->data == key)
            {
                return node;
            }

            if (key < node->data)
            {
                return (searchS(node->left, key));
            }
            else
            {
                return (searchS(node->right, key));
            }
        }

        Node* LCA(Node *root, int v1, int v2)
        {
            Node * V1_startNode = root;
            Node * v2_startNode = root;
            Node * saveNode = nullptr;
            while (V1_startNode == v2_startNode && V1_startNode != nullptr)
            {
                saveNode = V1_startNode;
                V1_startNode = SelectDirection(V1_startNode, v1);
                v2_startNode = SelectDirection(v2_startNode, v2);
            }
            return (saveNode);
        }

        Node *SelectDirection(Node *node, int key)
        {
            if (node->data == key)
            {
                return (nullptr);
            }
            if (node->data > key)
            {
                return (node->left);
            }
            else
            {
                return (node->right);
            }
        }
};


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
  	
  	int v1, v2;
  	std::cin >> v1 >> v2;
  
    Node *ans = myTree.lca(root, v1, v2);
    
  	std::cout << ans->data;

    return 0;
}