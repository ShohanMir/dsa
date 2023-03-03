#include <bits/stdc++.h>

using namespace std;

struct Node {
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
        cout << node->data << "-> ";
        if (node->left != NULL && vis[node->left->data] == 0) {
            cout << node->left->data << " ";
            q.push(node->left);
        }
        if (node->right != NULL && vis[node->right->data] == 0) {
            cout << node->right->data << " ";
            q.push(node->right);
        }
        cout << endl;
    }
}

void printLeafNodes(Node* root) {
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        cout << root->data << " ";
    }
    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

void printDegrees(Node* root) {
    if (root == NULL) {
        return;
    }
    if (root->left != NULL) {
        cout << root->data << ": " << root->left->data << " ";
    }
    if (root->right != NULL) {
        cout << root->data << ": " << root->right->data << " ";
    }
    cout << endl;
    printDegrees(root->left);
    printDegrees(root->right);
}

// fucntion for searching an element
bool search(Node* root, int key) {
    if (root == NULL) {
        return false;
    }
    if (root->data == key) {
        return true;
    }
    if (root->data > key) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

// function for finding the height of the tree
int height(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int lheight = height(root->left);
    int rheight = height(root->right);
    return max(lheight, rheight) + 1;
}

// function for finding the diameter of the tree
int diameter(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int lheight = height(root->left);
    int rheight = height(root->right);
    int ldiameter = diameter(root->left);
    int rdiameter = diameter(root->right);
    return max(lheight + rheight + 1, max(ldiameter, rdiameter));
}

//finding the entire size of the tree
int size(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return size(root->left) + size(root->right) + 1;
}

// finding the sum of all the elements in the tree
int sum(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return sum(root->left) + sum(root->right) + root->data;
}

// finding the maximum element in the tree
int maxElement(Node* root) {
    if (root == NULL) {
        return INT_MIN;
    }
    int lmax = maxElement(root->left);
    int rmax = maxElement(root->right);
    return max(lmax, max(rmax, root->data));
}

// finding the minimum element in the tree
int minElement(Node* root) {
    if (root == NULL) {
        return INT_MAX;
    }
    int lmin = minElement(root->left);
    int rmin = minElement(root->right);
    return min(lmin, min(rmin, root->data));
}

// removing an element from the tree
void remove(Node* root, int key) {
    if (root == NULL) {
        return;
    }
    if (root->data == key) {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return;
        }
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = remove(root->right, temp->data);
    } else if (root->data > key) {
        root->left = remove(root->left, key);
    } else {
        root->right = remove(root->right, key);
    }
    return root;
}

// insert an element at the end of the tree
void insert(Node* root, int key) {
    if (root == NULL) {
        root = new Node(key);
        return;
    }
    if (root->data > key) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
}

// function to insert an element at the front of the tree
void insertFront(Node* root, int key) {
    if (root == NULL) {
        root = new Node(key);
        return;
    }
    if (root->data > key) {
        root->left = insertFront(root->left, key);
    } else {
        root->right = insertFront(root->right, key);
    }
}

// function to insert an element at the middle of the tree
void insertMiddle(Node* root, int key) {
    if (root == NULL) {
        root = new Node(key);
        return;
    }
    if (root->data > key) {
        root->left = insertMiddle(root->left, key);
    } else {
        root->right = insertMiddle(root->right, key);
    }
}

// function to insert an element at the tree
void insertAt(Node* root, int key, int pos) {
    if (root == NULL) {
        root = new Node(key);
        return;
    }
    if (root->data > key) {
        root->left = insertAt(root->left, key, pos);
    } else {
        root->right = insertAt(root->right, key, pos);
    }
}

// function for finding the successor of an element
int successor(Node* root, int key) {
    if (root == NULL) {
        return INT_MIN;
    }
    if (root->data == key) {
        if (root->right != NULL) {
            Node* temp = root->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            return temp->data;
        } else {
            return INT_MIN;
        }
    }
    if (root->data > key) {
        return successor(root->left, key);
    } else {
        return successor(root->right, key);
    }
}



// driver code
int main() {
    Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 60);
    root = insert(root, 70);
    root = insert(root, 80);
    root = insert(root, 90);
    root = insert(root, 100);
    
    printDegrees(root);
    cout << endl;
    printLevelOrder(root);
    cout << endl;

    cout << "Height of the tree is " << height(root) << endl;
    cout << "Diameter of the tree is " << diameter(root) << endl;
    cout << "Size of the tree is " << size(root) << endl;
    cout << "Sum of the tree is " << sum(root) << endl;
    cout << "Maximum element in the tree is " << maxElement(root) << endl;
    cout << "Minimum element in the tree is " << minElement(root) << endl;
    cout << "Successor of the element is " << successor(root, 50) << endl;
    cout << "Removing the element is " << remove(root, 50) << endl;
    cout << "Inserting the element is " << insert(root, 50) << endl;
    cout << "Inserting the element is " << insertFront(root, 50) << endl;
    cout << "Inserting the element is " << insertMiddle(root, 50) << endl;
    // cout << "Inserting the element is " << insertAt(root, 50, 3) << endl;


    return 0;
};