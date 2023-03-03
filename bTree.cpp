#include <bits/stdc++.h>

using namespace std;

// create a binary tree
class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node (int value) {
            data = value;
            left = NULL;
            right = NULL;
        }
};

// add edge between two nodes
void addEdge(Node* root, Node* child) {
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

// print parents of a node
void printParents(Node* root, Node* parent) {
    if (root == NULL) {
        return;
    }
    if (parent == NULL) {
        cout << root->data << "->Root" << endl;
    } else {
        cout << root->data << "->" << parent->data << endl;
    }
    printParents(root->left, root);
    printParents(root->right, root);
}

// print children of a node
void printChildren(Node* root) {
    if (root == NULL) {
        return;
    }
    queue<Node*> q;
    q.push(root);
    int vis[100] = { 0 };
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        vis[node->data] = 1;
        if (node->left != NULL && vis[node->left->data] == 0) {
            q.push(node->left);
        }
        if (node->right != NULL && vis[node->right->data] == 0) {
            q.push(node->right);
        }
    }
    for (int i = 0; i < 100; i++) {
        if (vis[i] == 1) {
            cout << i << " ";
        }
    }
    cout << endl;
}

// insert an element into tree
void insert(Node* root, int value) {
    if (root == NULL) {
        return;
    }
    if (root->data > value) {
        if (root->left == NULL) {
            root->left = new Node(value);
        } else {
            insert(root->left, value);
        }
    } else {
        if (root->right == NULL) {
            root->right = new Node(value);
        } else {
            insert(root->right, value);
        }
    }
}

// delete an element from the tree
void deleteNode(Node* root, int value) {
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

// Search for an element in the tree
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

// traversing the tree in preorder
void preorder(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// traversing the tree in inorder
void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// traversing the tree in postorder
void postorder(Node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->right);
    postorder(root->left);
    cout << root->data << " ";
}

// find the maximum element in the tree
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

// find the minimum element in the tree
int findMin(Node* root) {
    if (root == NULL) {
        return INT_MAX;
    }
    int min = root->data;
    int leftMin = findMin(root->left);
    int rightMin = findMin(root->right);
    if (leftMin < min) {
        min = leftMin;
    }
    if (rightMin < min) {
        min = rightMin;
    }
    return min;
}

// find the height of the tree
int height(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
    }
}

// find the size of the tree
int size(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftSize = size(root->left);
    int rightSize = size(root->right);
    return leftSize + rightSize + 1;
}

// Finding the level which has maximum sum in the tree
int maxSumLevel(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int maxSum = root->data;
    int maxLevel = 1;
    int level = 1;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        if (node->left != NULL) {
            q.push(node->left);
        }
        if (node->right != NULL) {
            q.push(node->right);
        }
        if (q.empty()) {
            level++;
        }
        int sum = 0;
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            sum += temp->data;
        }
        if (sum > maxSum) {
            maxSum = sum;
            maxLevel = level;
        }
    }
    return maxLevel;
}

// Finding the least common ancestor (LCA) for a given pair of nodes
Node* leastCommonAncestor(Node* root, int value1, int value2) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == value1 || root->data == value2) {
        return root;
    }
    Node* left = leastCommonAncestor(root->left, value1, value2);
    Node* right = leastCommonAncestor(root->right, value1, value2);
    if (left != NULL && right != NULL) {
        return root;
    }
    if (left != NULL) {
        return left;
    }
    return right;
}

// finding the level that has the maximum sum in the binary tree
int maxSumLevel2(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int maxSum = root->data;
    int maxLevel = 1;
    int level = 1;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        if (node->left != NULL) {
            q.push(node->left);
        }
        if (node->right != NULL) {
            q.push(node->right);
        }
        if (q.empty()) {
            level++;
        }
        int sum = 0;
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            sum += temp->data;
        }
        if (sum > maxSum) {
            maxSum = sum;
            maxLevel = level;
        }
    }
    return maxLevel;
}

// Driver code
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Node* root = new Node(1);
    // insert(root->left, 2);
    // insert(root->right, 3);
    // insert(root->left->left, 4);
    // insert(root->left->right, 5);
    // insert(root->right->left, 6);
    // insert(root->right->right, 7);
    // insert(root->left->left->left, 8);
    // insert(root->left->left->right, 9);
    // insert(root->right->left->left, 10);
    // insert(root->right->left->right, 11);
    // insert(root, 12);
    // insert(root, 13);
    // insert(root, 14);
    // insert(root, 15);
    // insert(root, 16);
    // insert(root, 17);
    // insert(root, 18);
    // insert(root, 19);

    

    root->left = new Node(19);
    root->right = new Node(20);
    root->right->left = new Node(21);
    root->right->right = new Node(22);
    root->right->right->left = new Node(23);
    root->right->right->right = new Node(24);
    addEdge(root, new Node(3));

    deleteNode(root, 3);
    
    cout << "Preorder traversal of the given tree: ";
    preorder(root);
    cout << endl;

    cout << "Inorder traversal of the given tree: ";
    inorder(root);
    cout << endl;

    cout << "Postorder traversal of the given tree: ";
    postorder(root);
    cout << endl;

    cout << "Height of the tree: " << height(root) << endl;
    cout << "Size of the tree: " << size(root) << endl;
    cout << "Maximum element in the tree: " << findMax(root) << endl;
    cout << "Minimum element in the tree: " << findMin(root) << endl;
    cout << "Level which has maximum sum in the tree: " << maxSumLevel(root) << endl;
    cout << "Least common ancestor of the given pair of nodes: " << leastCommonAncestor(root, 13, 14)->data << endl;
    cout << "Least common ancestor of the given pair of nodes: " << leastCommonAncestor(root, 8, 9)->data << endl;
    cout << "Least common ancestor of the given pair of nodes: " << leastCommonAncestor(root, 13, 17)->data << endl;

    // cout << "deleted Node: ";
    // cout << endl;

    // print parent
    // printParents(root);
    // cout << endl;
    // print children
    printChildren(root);
    cout << endl;
    // print siblings
    // printSiblings(root);

    return 0;
};