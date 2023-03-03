#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// addEdge is used to add an edge between two nodes
void addEdge(Node *root, Node *child) {
    if (root == NULL) {
        return;
    }
    if (root->data > child->data) {
        if (root->left == NULL) {
            root->left = child;
        } else {
            addEdge(root->left, child);
        }
    } else {
        if (root->right == NULL) {
            root->right = child;
        } else {
            addEdge(root->right, child);
        }
    }
}

Node* instertBST(Node *root, int value) {

    if(root == NULL) return new Node(value);

    if (value < root->data) {
        root->left = instertBST(root->left, value);
    } else {
        root->right = instertBST(root->right, value);
    }
    return root;
};

void inorder(Node *root) {
    if(root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
};

void preorder(Node *root) {
    if(root == NULL) return;

    cout << root->data << " ";
    preorder(root->right);
    preorder(root->left);
}

// delete an element from the tree
void deleteNode(Node *root, int value) {
    if (root == NULL) {
        return;
    }
    if (root->data > value) {
        deleteNode(root->left, value);
    } else if (root->data < value) {
        deleteNode(root->right, value);
    } else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        } else if (root->left == NULL) {
            Node* temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == NULL) {
            Node* temp = root;
            root = root->left;
            delete temp;
        } else {
            Node* temp = root->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            root->data = temp->data;
            deleteNode(root->right, temp->data);
        }
    }
}

// lever order treversal
void leverOrder(Node *root) {
    if(root == NULL) return;
    queue<Node *> q;
    q.push(root);
    while(!q.empty()) {
        Node *temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if(temp->left != NULL) q.push(temp->left);
        if(temp->right != NULL) q.push(temp->right);
    }
}

// reverse lever order treversal
void reverseLeverOrder(Node *root) {
    if(root == NULL) return;
    stack<Node *> s;
    s.push(root);
    while(!s.empty()) {
        Node *temp = s.top();
        s.pop();
        cout << temp->data << " ";
        if(temp->right != NULL) s.push(temp->right);
        if(temp->left != NULL) s.push(temp->left);
    }
}

// reverse the tree
void reverseTree(Node *root) {
    if(root == NULL) return;
    stack<Node *> s;
    s.push(root);
    while(!s.empty()) {
        Node *temp = s.top();
        s.pop();
        if(temp->right != NULL) s.push(temp->right);
        if(temp->left != NULL) s.push(temp->left);
        Node *temp2 = temp->left;
        temp->left = temp->right;
        temp->right = temp2;
    }
}




int main() {
    Node *root = NULL;
    root = instertBST(root, 5);
    instertBST(root, 1);
    instertBST(root, 3);
    instertBST(root, 4);
    instertBST(root, 2);
    instertBST(root, 7);

    // deleteNode(root, 1);
    deleteNode(root, 7);


    // addEdge(root, new Node(6));

    inorder(root);
    cout << endl;

    preorder(root);
    cout << endl;

    reverseLeverOrder(root);
    cout << endl;

    

    return 0;
};