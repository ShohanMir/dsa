#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
    int value;
    Node *left, *right;
    int height;

    Node(int data) {
        value = data;
        left = NULL;
        right = NULL;
    }
};

int max(int a, int b) {
    return (a > b)? a : b;
}

int height(Node *N) {
    if(N == NULL) return 0;
    return N->height;
}

Node* newNode(int data) {
    Node* node = new Node(data);
    node->height = 1;
    return node;
}

Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(Node *N) {
    if(N==NULL) return 0;
    return height(N->left) - height(N->right);
}

Node* insert(Node* node, int data) {
    if(node == NULL)
        return(newNode(data));

    if(data < node->value){
        node->left = insert(node->left, data);
    }else if(data > node->value) {
        node->right = insert(node->right, data);
    }else {
        return node;
    }

    node->height = 1+ max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if(balance > 1 && data < node->left->value)
        return rightRotate(node);
    
    if(balance < -1 && data > node->right->value)
        return leftRotate(node);

    if(balance > 1 && data > node->left->value){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if(balance < -1 && data < node->right->value) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
};

void preOrder(Node *root)
{
    if(root != NULL)
    {
        cout << root->value << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

        /* The constructed AVL Tree would be
                30
            / \
            20 40
            / \ \
        10 25 50
    */

    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    preOrder(root);

    return 0;
}
