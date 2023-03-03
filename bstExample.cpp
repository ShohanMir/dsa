#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node (int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

Node* insertBST(Node *root, int value) {
    if(root == NULL) return new Node(value);

    if (value < root->data) {
        root->left = insertBST(root->left, value);
    } else {
        root->right = insertBST(root->right, value);
    }

    return root;
}

void inorder(Node *root) {
    if(root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

bool search(Node* root, int value) {
    if (root == NULL) {
        return false;
    }
    if (root->data == value) {
        return true;
    }
    if (root->data > value) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

Node* inorderSucc(Node* root) {
    Node* curr = root;
    while(curr && curr->left != NULL) {
        curr = curr->left;
    }
    return curr;
}

Node* deletBst(Node* root, int value) {
    if (root == NULL) {
        return NULL;
    }

    if (value < root->data) {
        root->left = deletBst(root->left, value);
    } else if(value > root->data) {
        root->right = deletBst(root->right, value);
    } else {
        if(root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }else if(root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deletBst(root->right, root->data);
    }
    return root;
}

// Node* deleteNode(Node* root, int value) {
//     if(root == NULL) return NULL;

//     if(value < root->data) {
//         root->left = deleteNode(root->left, value);
//     } else if(value > root->data) {
//         root->right = deleteNode(root->right, value);
//     } else {
//         if(root->left == NULL && root->right == NULL) {
//             delete root;
//             root = NULL;
//         } else if(root->left == NULL) {
//             Node* temp = root->right;
//             delete root;
//             return temp;
//         } else if(root->right == NULL) {
//             Node* temp = root->left;
//             delete root;
//             return temp;
//         }
//         Node* temp = findMax(root->right);
//         root->data = temp->data;
//         root->right = deleteNode(root->right, root->data);
//     }
//     return root;
// }

int findMax(Node* root) {
    if (root == NULL) {
        return INT_MIN;
    }
    int max = root->data;
    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);
    if (leftMax > max) {
        max = leftMax;
    }
    if (rightMax > max) {
        max = rightMax;
    }
    return max;
}

int findMin (Node *root) {
    if (root == NULL) return INT_MAX;

    int min = root->data;
    int leftMin = findMin(root->left);
    int rightMin = findMin(root->right);

    if(leftMin < min) {
        min = leftMin;
    }
    if (rightMin < min) {
        min = rightMin;
    }
    return min;
}

//Driver code

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    Node *root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);

    inorder(root);
    cout << endl;

    root = deletBst(root, 4);

    inorder(root);
    cout << endl;

    cout<< "find: " << search(root, 6) << endl;

    cout<< "Max: "<< findMax(root)<< endl;
    cout<< "Max: "<< findMin(root)<< endl;

    // cout<< endl;

    return 0;
}